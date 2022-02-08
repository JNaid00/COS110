#ifndef BABUSHKAEXCEPTION_H
#define BABUSHKAEXCEPTION_H
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class BabushkaException
{
    public:
        virtual void printMessage() = 0;
};
#endif