#ifndef LIGHTBLUEBABUSHKA_H
#define LIGHTBLUEBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "BlueBabushka.h"


class LightBlueBabushka : public BlueBabushka
{
    public:
        LightBlueBabushka(const unsigned char *id, unsigned int amount);

        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif