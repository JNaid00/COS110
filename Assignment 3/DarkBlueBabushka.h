#ifndef DARKBLUEBABUSHKA_H
#define DARKBLUEBABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "BlueBabushka.h"


class DarkBlueBabushka : public BlueBabushka
{
    public:
        DarkBlueBabushka(const unsigned char *id, unsigned int amount);

        virtual void decrypt(unsigned char* data, int size);
        virtual void encrypt(unsigned char* data, int size);
};
#endif