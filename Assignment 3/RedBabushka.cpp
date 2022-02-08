#include "RedBabushka.h"
#include "Babushka.h"
#include "RotateException.h"
//#include "UnderflowException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

RedBabushka::RedBabushka(const unsigned char* id,  unsigned int rotationAmount) : Babushka(id)
{
    this->rotationAmount = rotationAmount;
}

void RedBabushka::encrypt(unsigned char* data, int size)
{
    unsigned char temp;
    // try
    // {
        if (this->rotationAmount >= size)
        {
            throw RotateException();
        }

        for (int r = 0; r < this->rotationAmount; r++)
        {
            temp = data[size-1];
            for (int i = (size-1); i > 0; i--) //i now equal to the last index
            {
                data[i] = data[i-1];
            }
            data[0] = temp;
        }
    // }
    // catch(RotateException a)
    // {
    //     a.printMessage();
    // }
    
    
}

void RedBabushka::decrypt(unsigned char* data, int size)
{
    unsigned char temp;
    // try
    // {
        if (this->rotationAmount >= size)
        {
            throw RotateException();
        }

        for (int r = 0; r < this->rotationAmount; r++)
        {
            temp = data[0];
            for (int i = 0; i < size; i++) //i now equal to the last index
            {
                data[i] = data[i+1];
            }
            data[size-1] = temp;
        }
    // }
    // catch(RotateException a)
    // {
    //     a.printMessage();
    // }
    
    
}