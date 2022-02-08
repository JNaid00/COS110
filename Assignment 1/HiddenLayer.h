#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H
#include "HiddenNeuron.h"
#include "InputLayer.h"
//#include "HiddenLayer.h"
#include <string>

//using namespace std;

class HiddenNeuron;

class HiddenLayer
{
    private:
        int numNeurons;
        HiddenNeuron **neurons;
        std::string activation;
    public:
       HiddenLayer(int numNeurons, HiddenNeuron** neurons, std::string activation);
       ~HiddenLayer();
       HiddenNeuron** getNeurons();
       void setNeurons(HiddenNeuron** neurons);
       int getNumNeurons();
       void setNumNeurons(int numNeurons);
       void forward(HiddenLayer* prevLayer);
       void forward(InputLayer* inputLayer);
       void printLayer();
       void clearLayer();
};
#endif