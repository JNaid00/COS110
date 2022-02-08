#ifndef CONTROLLEREXCEPTION_H
#define CONTROLLEREXCEPTION_H
#include "BabushkaException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class ControllerException
{
    private:
        BabushkaException* babushkaException;
        bool hasBabushka;
        std::string customMessage;
    public:
        ControllerException(std::string customMessage);
        ControllerException(BabushkaException& babushkaException, std::string customMessage);
        void printMessage();
};
#endif