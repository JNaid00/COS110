#include "Controller.h"
#include "Babushka.h"
#include "GoldBabushka.h"
#include "YellowBabushka.h"
#include "GreenBabushka.h"
#include "RedBabushka.h"
#include "LightBlueBabushka.h"
#include "DarkBlueBabushka.h"
#include "ReturnStruct.h"
#include "ControllerException.h"
// #include "DisplacementException.h"
// #include "RotateException.h"
// #include "OverflowException.h"
// #include "UnderflowException.h"
#include "BabushkaException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Controller::Controller(std::string filePath)
{
    ifstream inputfile;
    inputfile.open(filePath.c_str());
    string line;
    getline(inputfile,line);
    line.erase(0, line.find(":") +1);
    stringstream x(line);
    x >> this->numBabushkas;
    //cout <<"NewYork: "<< this->numBabushkas << endl;
    // //create the Babushka array
    this->babushkaArr = new Babushka*[this->numBabushkas];
    // ///
    string name, strID;
    char type;
    unsigned char* id = NULL;
    int different;
    stringstream a;
    unsigned char xorValue;
    for (int i = 0; i < this->numBabushkas; i++)
    {
        getline(inputfile,line);
        
        //cout <<"NewYork: " << line << endl;
        name = line.substr(0,line.find(":"));
        //cout <<"NewYork: " << name << endl;
        if (name == "gold")
        {
            //cout <<"NewYork: " << name << endl;
             type = 'G';
        }
        else
        {
            //cout <<"NewYork: " << name << endl;
            type = name[0];
            //cout <<"NewYork: " << type << endl;
        }
        //cout <<"NewYork: first " << type << endl;

        line.erase(0, line.find(":") +1);

        if (type == 'y')
        strID = line;
        else if(type == 'G')
        {
            strID = line.substr(0,line.find(":"));
            line.erase(0, line.find(":") +1);
            xorValue = line[0];
        }
        else
        {
            strID = line.substr(0,line.find(":"));
            line.erase(0, line.find(":") +1);
            a << line;
            a >> different;
        }
        id = new unsigned char[10];
        //cout <<"NewYork: " << strID << endl;
        for (int j = 0; j < 10; j++)
        {
            id[j] = strID[j];
        }
       //cout <<"NewYork: " << type << endl;
        switch (type){
            case 'G':
                this->babushkaArr[i] = new GoldBabushka(id,xorValue);
                // cout <<"NewYork: " << endl;
                break;
            case 'y':
                this->babushkaArr[i] = new YellowBabushka(id);
                //cout <<"NewYork: " << endl;
                break;
            case 'g':
                this->babushkaArr[i] = new GreenBabushka(id,different);
                //cout <<"NewYork: " << strID << endl;
                break;
            case 'r':
                this->babushkaArr[i] = new RedBabushka(id,different);
                //cout <<"NewYork: r" << endl;
                break;
            case 'l':
                this->babushkaArr[i] = new LightBlueBabushka(id,different);
                //cout <<"NewYork: l" << endl;
                break;
            case 'd':
                this->babushkaArr[i] = new DarkBlueBabushka(id,different);
                //cout <<"NewYork: d" << endl;
                break;
        }

        

    a.clear();
    //i = this->numBabushkas;
    }
}

Controller::~Controller()
{
    for (int i = 0; i<this->numBabushkas;i++)
    {
        delete this->babushkaArr[i];
    }
    delete [] this->babushkaArr;
     //cout <<"NewYork: ";
}

ReturnStruct Controller::expandArray(unsigned char* array, int currentSize, const unsigned char* id, int idSize)
{
    ReturnStruct changed;
    changed.arraySize = currentSize + 2*idSize;
    changed.returnArray = new unsigned char[changed.arraySize];
    int count = 0;
    for (int i = 0; i < idSize; i++)
    {
        changed.returnArray[i] = id[i];
        changed.returnArray[changed.arraySize -idSize + i] = id[i];
    }
    for (int i = idSize; i < (currentSize + idSize);i++)
    {
        changed.returnArray[i] = array[count];
        count++;
    }
    //Hello
    // for (int i =0; i < currentSize; i++)
    // {
    //     delete array[i];
    // }
    delete [] array;
  return changed;
}


ReturnStruct Controller::reduceArray(unsigned char* array, int currentSize, const unsigned char* expectedId, int idSize)
{
    //cout <<"NewYork: Reduce " << currentSize << endl;
    int newSize = currentSize -(2*idSize);
    //cout <<"NewYork: Reduce " << newSize << endl;
    if (newSize < 0)
    {
        throw ControllerException("size exception");
    }
    // throw ControllerException("size exception");
    for (int i = 0; i < idSize; i++)
    {
        if ((array[i] != expectedId[i]) || (array[currentSize - idSize + i] != expectedId[i]))
        {
            throw ControllerException("id mismatch exception");
        }
    }
    //throw ControllerException("id mismatch exception");
    ReturnStruct changed;
    changed.arraySize = newSize;
    changed.returnArray = new unsigned char[changed.arraySize];
    int count = 0;
    for (int i = idSize; i < (currentSize - idSize); i++)
    {
        changed.returnArray[count] = array[i];
        count++;
    }
    delete [] array;
    return changed;
}

void Controller::printArray(unsigned char* array, int size)
{
    cout << "[";
    for (int i = 0; i < (size-1); i++)
    {
        cout << array[i]<<",";
    }
    cout << array[size -1]<< "]" << endl;
}

ReturnStruct Controller::encrypt(const unsigned char* array, int size)
{
    int copySize = size;
    unsigned char* copyArray = new unsigned char[copySize];
    for (int i = 0; i < copySize;i++)
    {
        copyArray[i] = array[i];
    }
    
    ReturnStruct encrypted;
    encrypted.arraySize = copySize;
    encrypted.returnArray = copyArray;
    Controller::printArray(encrypted.returnArray,encrypted.arraySize);
    try
    {
        for (int i = 0; i < this->numBabushkas;i++)
        {
           encrypted = expandArray(encrypted.returnArray,encrypted.arraySize,this->babushkaArr[i]->getId(),this->babushkaArr[i]->getIdLength());
           this->babushkaArr[i]->encrypt(encrypted.returnArray, encrypted.arraySize);
           Controller::printArray(encrypted.returnArray, encrypted.arraySize);
           
        //    if (i == 6)
        //    {
        //        //cout <<this->babushkaArr[i]->getId() << endl;
        //        i = this->numBabushkas; //JUst for testing
        //    }
        }
    }
    catch(BabushkaException& e)
    {
        throw ControllerException(e, "encrypt exception");
    }
    // catch(DisplacementException& e)
    // {
    //     e.printMessage();
    // }
    // catch(OverflowException& e)
    // {
    //     e.printMessage();
    // }
    // catch(RotateException& e)
    // {
    //     e.printMessage();
    // }
    // catch(UnderflowException& e)
    // {
    //     e.printMessage();
    // }

    return encrypted;
}

ReturnStruct Controller::decrypt(const unsigned char* array, int size)
{
    //int copySize = size;
    ReturnStruct decrypted;
    decrypted.arraySize = size;
    //decrypted.returnArray = copyArray;

    //unsigned char* copyArray = new unsigned char[copySize];
    decrypted.returnArray = new unsigned char[decrypted.arraySize];
    for (int i = 0; i < size;i++)
    {
       decrypted.returnArray[i] = array[i];
    }
    //Testing
    // if (size == 164)
    // copyArray[162] = 'E';
    /////////////

    Controller::printArray(decrypted.returnArray,decrypted.arraySize);
    
    //
     
    
    try
    {
        for (int i = (this->numBabushkas -1); i >= 0 ;i--)
        {
            //cout <<"NewYork: " << size << endl;
           this->babushkaArr[i]->decrypt(decrypted.returnArray, decrypted.arraySize);
           decrypted = reduceArray(decrypted.returnArray,decrypted.arraySize,this->babushkaArr[i]->getId(),this->babushkaArr[i]->getIdLength());
           
           Controller::printArray(decrypted.returnArray, decrypted.arraySize);
        //     if (i == 0)
        //    {
        //        //cout <<this->babushkaArr[i]->getId() << endl;
        //        i = -1; //JUst for testing
        //    }
        }
    }
    catch(BabushkaException& e)
    {
        throw ControllerException(e, "decrypt exception");
    }

    return decrypted;  
}