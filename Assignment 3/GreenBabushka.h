#ifndef GREENBABUSHKA_H
#define GREENBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Babushka.h"

class GreenBabushka : public Babushka
{
    private:
        unsigned int displacement;
    public:
        GreenBabushka(const unsigned char* id,  unsigned int displacement);

        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif