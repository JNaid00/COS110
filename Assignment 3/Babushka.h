#ifndef BABUSHKA_H
#define BABUSHKA_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Babushka
{
    protected:
        const unsigned char *id; //contains alphanumeric characters
        static const int ID_LENGTH = 10; //Length id array;
        static const unsigned char MIN_VALUE_INCLUSIVE = 32;
        static const unsigned char MAX_VALUE_INCLUSIVE = 126;
    public:
        Babushka(const unsigned char *id);
        const int getIdLength();
        const unsigned char* getId();

        virtual ~Babushka();
        virtual void decrypt(unsigned char* data, int size) = 0;
        virtual void encrypt(unsigned char* data, int size) = 0;
};
#endif