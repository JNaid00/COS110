#include "YellowBabushka.h"
#include "Babushka.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

YellowBabushka::YellowBabushka(const unsigned char* id) : Babushka(id)
{
    
}

void YellowBabushka::encrypt(unsigned char* data, int size)
{
    int half = size /2;
    unsigned char temp;
    for (int i = 0; i < half; i++)
    {
        temp = data[i];
        data[i] = data[size-1-i];
        data[size-1-i] = temp;
    }
    
}

void YellowBabushka::decrypt(unsigned char* data, int size)
{
    int half = size /2;
    unsigned char temp;
    for (int i = 0; i < half; i++)
    {
        temp = data[i];
        data[i] = data[size-1-i];
        data[size-1-i] = temp;
    }
    
}