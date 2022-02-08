#include "InputLayer.h"
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

InputLayer::InputLayer(int numInputs)
{
    //cout << numInputs<< endl;
    this->numInputs = numInputs;   
    inputs = NULL;
}

InputLayer::~InputLayer()
{
    delete [] inputs;
    inputs = NULL;
}

double *InputLayer::getInputs()
{
    return inputs;
}

int InputLayer::getNumInputs()
{
    return numInputs;
}

void InputLayer::setInputs(double* inputs) 
{
    if (this->inputs == NULL)
    {
        this->inputs = inputs;
    }
    else
    {
        delete [] this->inputs;
        //inputs = NULL;
        this->inputs = inputs;
    }

}

void InputLayer::setNumInputs(int numInputs)
{
    this->numInputs = numInputs;
}

void InputLayer::printLayer()
{
    cout << "i:" << numInputs << endl;
    //cout << << endl;
}

void InputLayer::clearLayer()
{
    if (inputs != NULL)
    {
        for (int i = 0; i < numInputs; i++)
        {
            inputs[0] = 0;
            //cout << inputs[0] << endl;
        }
    }
    else
    if (inputs == NULL)
    {

    }
}