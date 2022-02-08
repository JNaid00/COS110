#include "HiddenNeuron.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

/////
//class HiddenNeuron;
/////

HiddenLayer::HiddenLayer(int numNeurons, HiddenNeuron** neurons, string activation)
{
    this->numNeurons = numNeurons;
    this->activation= activation;
    this->neurons = neurons;
}

HiddenLayer::~HiddenLayer()
{
    for (int i = 0; i < this->numNeurons; i++)
    {
        delete neurons[i];
    }
    delete [] neurons;
}

HiddenNeuron** HiddenLayer::getNeurons()
{
    return this->neurons;
}

void HiddenLayer::setNeurons(HiddenNeuron** neurons) //Need to ask
{
    if (this->neurons != NULL)
    {
        for (int i = 0; i < this->numNeurons; i++)
        {
            delete this->neurons[i];
        }
        delete [] this->neurons;   
    }
    this->neurons = neurons;
   

}

int HiddenLayer::getNumNeurons()
{
    return numNeurons;
}

void HiddenLayer::setNumNeurons(int numNeurons)
{
    this->numNeurons = numNeurons;
}

void HiddenLayer::forward(HiddenLayer* prevLayer) //Need to ask
{
    //HiddenNeuron **prevLayerNeurons = prevLayer->getNeurons();
    double newValue = 0;
    for (int i = 0; i < this->numNeurons; i++)
    {
        newValue = 0;
        neurons[i]->forward(prevLayer);
        if (this->activation == "relu")
        {
           // newValue = fmax(0,newValue);
            neurons[i]->activateReLU();
        }
        if (this->activation == "sigmoid")
        {
        //    newValue = 1/(1+exp(-newValue));
            neurons[i]->activateSigmoid();
        }
    }
    
}

void HiddenLayer::forward(InputLayer* inputLayer) //need to ask
{
    double newValue = 0;
    for (int i = 0; i < this->numNeurons; i++)
    {
        neurons[i]->forward(inputLayer); //ask
        if (this->activation == "relu")
        {
           // newValue = fmax(0,newValue);
            neurons[i]->activateReLU();
        }
        if (this->activation == "sigmoid")
        {
        //    newValue = 1/(1+exp(-newValue));
            neurons[i]->activateSigmoid();
        }
    }
}

void HiddenLayer::printLayer()
{
    cout << "h:" << numNeurons << ":" << activation << endl;
}

void HiddenLayer::clearLayer()
{
    if (this->neurons != NULL)
    {
        for (int i = 0; i < this->numNeurons;i++)
         {
             neurons[i]->setValue(0);
         }
    }
}