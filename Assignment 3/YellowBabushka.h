#ifndef YELLOWBABUSHKA_H
#define YELLOWBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Babushka.h"

class YellowBabushka : public Babushka
{
    public:
        YellowBabushka(const unsigned char* id);

        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif