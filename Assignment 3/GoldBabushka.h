#ifndef GOLDBABUSHKA_H
#define GOLDBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Babushka.h"

class GoldBabushka : public Babushka
{
    private:
        unsigned char xorValue;
    public:
        GoldBabushka(const unsigned char* id, unsigned char xorValue);

        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif