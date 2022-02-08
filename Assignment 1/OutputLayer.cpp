#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

OutputLayer::OutputLayer(int numWeights, double* weights)
{
    this->numWeights = numWeights;
    this->weights = weights;
    this->outputValue = 0;
}

OutputLayer::~OutputLayer()
{
    delete [] weights;
}

double OutputLayer::getOutputValue()
{
    return outputValue;
}

void OutputLayer::setOutputValue(double outputValue)
{
    this->outputValue = outputValue;
}

void OutputLayer::forward(HiddenLayer* lastHiddenLayer) //Need to ask
{

    for (int i = 0; i < numWeights; i++)
    {
        this->outputValue = this->outputValue + (lastHiddenLayer->getNeurons()[i]->getValue() * weights[i]);
    }
}

void OutputLayer::printLayer()
{
    cout << "o:1" << endl;
}

void OutputLayer::clearLayer()
{
    //cout << outputValue << endl;
    this->outputValue = 0;
    //cout << outputValue << endl;
}