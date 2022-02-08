#include "GoldBabushka.h"
#include "Babushka.h"
#include "OverflowException.h"
#include "UnderflowException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

GoldBabushka::GoldBabushka(const unsigned char* id, unsigned char xorValue) : Babushka(id)
{
    this->xorValue = xorValue;
}

void GoldBabushka::encrypt(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = (data[i] ^ this->xorValue);
    }

    // try
    // {
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

void GoldBabushka::decrypt(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = (data[i] ^ this->xorValue);
    }
    
    // try
    // {
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