#include "GreenBabushka.h"
#include "Babushka.h"
#include "DisplacementException.h"
//#include "UnderflowException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
//using namespace std;/////remove
GreenBabushka::GreenBabushka(const unsigned char* id,  unsigned int displacement) : Babushka(id)
{
    this->displacement = displacement;
}

void GreenBabushka::encrypt(unsigned char* data, int size)
{
    unsigned char temp;
    // try
    // {
    //std::cout << "Newyork: "<<size << std::endl;
    //std::cout << "Newyork: "<<data[size-2] << std::endl;
    if (this->displacement >= (size - 1))
    {
       throw DisplacementException();
    }
    for (int i = 0; (i +this->displacement +1) < size;i = i + this->displacement + 2)       
    {
        // if (size == 164)
        // {
        //     //std::cout << i << std::endl;
        //     std::cout << data[163] << std::endl;

        // }
        
        temp = data[i];
        data[i] = data[i + this->displacement + 1];
        data[i + this->displacement + 1] = temp;
        //if (size == 164)
        // {
        //     //std::cout << i << std::endl;
        //     std::cout << data[163] << std::endl;

        // }
        
    }
   //std::cout << "Newyork: "<<data[size-2] << std::endl;  
    

    // }
    // catch(DisplacementException errorOccur)
    // {
    //     errorOccur.printMessage();
    // }
    
}

void GreenBabushka::decrypt(unsigned char* data, int size)
{
    unsigned char temp;
    // try
    // {
       // std::cout << "NewYork: " << std::endl;
        if (this->displacement >= (size - 1))
        {
            throw DisplacementException();
        }
        
            for (int i = 0; (i +this->displacement +1) < size;i = i + this->displacement + 2)
            {
                temp = data[i];
                data[i] = data[i + this->displacement + 1];
                data[i + this->displacement + 1] = temp;
            }
    // }
    // catch(DisplacementException errorOccur)
    // {
    //     errorOccur.printMessage();
    // }
    
}