#include "ControllerException.h"
#include "BabushkaException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ControllerException::ControllerException(std::string customMessage)
{
    this->customMessage = customMessage;
    this->hasBabushka = false;
}

ControllerException::ControllerException(BabushkaException& babushkaException, std::string customMessage)
{
    this->customMessage = customMessage;
    this->babushkaException = &babushkaException;
    this->hasBabushka = true;
}

void ControllerException::printMessage()
{
    cout << this->customMessage << endl;
    if (this->hasBabushka == true)
    {
        this->babushkaException->printMessage();
    }
}
