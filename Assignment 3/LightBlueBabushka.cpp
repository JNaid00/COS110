#include "LightBlueBabushka.h"
#include "BlueBabushka.h"
#include "Babushka.h"
#include "OverflowException.h"
#include "UnderflowException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// using namespace std;

LightBlueBabushka::LightBlueBabushka(const unsigned char *id, unsigned int amount) : BlueBabushka(id, amount)
{

}

void LightBlueBabushka::encrypt(unsigned char* data, int size)
{
    // try
    // {
        //std::cout << "NewYork light blue"<< std::endl; 
        //std::cout << "NewYork light blue "<< " " << (data[57] + 0) << " " <<data[57]<<  std::endl;
        for(int i = 0 ; i < size; i++)
        {
            data[i] += BlueBabushka::amount;
            // if (data[i] > 126)
            // std::cout << "NewYork light blue " <<i << " " << (data[i] + 0) << " " <<data[i]<<  std::endl;
        }
        for(int i = 0 ; i < size; i++)
        {
            if (data[i] > Babushka::MAX_VALUE_INCLUSIVE)
            {
               // OverflowException errorOccur
               //std::cout << "NewYork" << data[i] << ":"<< std::endl;
                throw OverflowException();
            }
            if (data[i] < Babushka::MIN_VALUE_INCLUSIVE)
            {
                //UnderflowException errorOccur;
                
                throw UnderflowException();
            }
        }
    // }
    // catch(OverflowException errorOccur)
    // {
    //     errorOccur.printMessage();
    // }
    // catch(UnderflowException errorOccur)
    // {
    //     errorOccur.printMessage();
    // }
       
    
}

void LightBlueBabushka::decrypt(unsigned char* data, int size)
{
    // try
    // {
        for(int i = 0 ; i < size; i++)
        {
            data[i] -= BlueBabushka::amount;
        }
        for(int i = 0 ; i < size; i++)
        {
            if (data[i] > Babushka::MAX_VALUE_INCLUSIVE)
            {
               // OverflowException errorOccur
                throw OverflowException();
            }
            if (data[i] < Babushka::MIN_VALUE_INCLUSIVE)
            {
                //UnderflowException errorOccur;
                throw UnderflowException();
            }
        }
    // }
    // catch(OverflowException errorOccur)
    // {
    //     errorOccur.printMessage();
    // }
    // catch(UnderflowException errorOccur)
    // {
    //     errorOccur.printMessage();
    // }
}