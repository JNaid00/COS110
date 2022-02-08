#include "DarkBlueBabushka.h"
#include "BlueBabushka.h"
#include "Babushka.h"
#include "OverflowException.h"
#include "UnderflowException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

DarkBlueBabushka::DarkBlueBabushka(const unsigned char *id, unsigned int amount) : BlueBabushka(id, amount)
{

}

void DarkBlueBabushka::encrypt(unsigned char* data, int size)
{
    // try
    // {
        //cout << "NewYork: Dark blue" << endl;
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

void DarkBlueBabushka::decrypt(unsigned char* data, int size)
{
    // try
    // {
        for(int i = 0 ; i < size; i++)
        {
            data[i] += BlueBabushka::amount;
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