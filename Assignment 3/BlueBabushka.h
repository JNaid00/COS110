#ifndef BLUEBABUSHKA_H
#define BLUEBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Babushka.h"

class BlueBabushka : public Babushka
{
    protected:
        unsigned int amount;
    public:
        BlueBabushka(const unsigned char* id, unsigned int amount);

        virtual void decrypt(unsigned char* data, int size) = 0;
        virtual void encrypt(unsigned char* data, int size) = 0;
};
#endif