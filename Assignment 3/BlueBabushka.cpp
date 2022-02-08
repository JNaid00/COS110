#include "BlueBabushka.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

BlueBabushka::BlueBabushka(const unsigned char* id, unsigned int amount) : Babushka(id)
{
    this->amount = amount;
}