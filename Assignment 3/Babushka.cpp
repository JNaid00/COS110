#include "Babushka.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Babushka::Babushka(const unsigned char *id)
{
    this->id = id;
}
Babushka::~Babushka() //Must verify how to check if id exist
{
    if (this->id != NULL)
    {
        delete [] this->id;
        this->id = NULL;
    }
    //cout << "Done" << endl;

}

const int Babushka::getIdLength()
{
    return this->ID_LENGTH;
}

const unsigned char* Babushka::getId()
{
     //const unsigned char* newid = this->id;
     return this->id;
}
