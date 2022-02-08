#include "InputLayer.h"
#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;
//class HiddenLayer;

HiddenNeuron::HiddenNeuron(int numWeights, double* weights)
{
    this->value = 0;
    this->numWeights = numWeights;
    this->weights = weights;
}

HiddenNeuron::~HiddenNeuron()
{
    delete [] weights;
    weights = NULL;
}

double HiddenNeuron::getValue()
{
    return value;
}

void HiddenNeuron::setValue(double value)
{
    this->value = value;    
}

void HiddenNeuron::forward(HiddenLayer* prevLayer)  //Problably incorrect
{                   
    for (int i = 0; i < numWeights; i++)
    {
        value = value + (weights[i] * (prevLayer->getNeurons()[i]->getValue()));
    }
}

void HiddenNeuron::forward(InputLayer* inputLayer) //Problably incorrect
{
   // double *inputs = input->getInputs();
    for (int i = 0; i < numWeights; i++)
    {
        value = value + (weights[i] * inputLayer->getInputs()[i]);
    }
}

void HiddenNeuron::activateReLU()
{
    value = max(0.0,value);  //Check to use fmax
}

void HiddenNeuron::activateSigmoid()
{
    value = 1/(1+exp(-value));
}