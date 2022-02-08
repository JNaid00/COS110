#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "HiddenNeuron.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
//using namespace std;

class NeuralNetwork
{
    private:
        InputLayer* inputLayer;
        int numHiddenLayers;
        HiddenLayer** hiddenLayers;
        OutputLayer* outputLayer;
    public:
        NeuralNetwork(std::string filePath);
        ~NeuralNetwork();
        double forward(double *input);
        void printNetwork();
        void clearNetwork();

};
#endif
