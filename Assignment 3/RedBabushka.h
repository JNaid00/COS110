#ifndef REDBABUSHKA_H
#define REDBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Babushka.h"

class RedBabushka : public Babushka
{
    private:
        unsigned int rotationAmount;
    public:
        RedBabushka(const unsigned char* id,  unsigned int rotationAmount);

        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif