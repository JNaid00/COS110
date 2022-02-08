#include "HiddenNeuron.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "NeuralNetwork.h"
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

NeuralNetwork::NeuralNetwork(string filePath)
{
    ifstream inputfile;
    inputfile.open(filePath.c_str());
    string line;

    //InputLayer:
   //getline(inputfile,line);    //On the first line of file, Inputer layer size
    inputfile >> line;
    //cout << line << endl;
    int sizeInputLayer;
    stringstream x(line.substr(2,line.size()));
    x >> sizeInputLayer;
    int prevLayerSize = 0;
    prevLayerSize = sizeInputLayer; //This will be the value to determine the number of weights in each line
    
    //double *inputs = new double[sizeInputLayer]; ///Need to intitalse inputs array at end
    this->inputLayer = new InputLayer(sizeInputLayer);
    //HiddenLayer:
   // getline(inputfile,line); //On second line of file, Number of hidden layers
    inputfile >> line;
    stringstream a(line.substr(line.find(':')+1,line.size()));
    a >> numHiddenLayers;
    this->hiddenLayers = new HiddenLayer*[numHiddenLayers];


    HiddenNeuron **inputNeurons;
    double *weights;
    for (int i = 0; i < numHiddenLayers ;i++)
    {
        //getline(inputfile,line); //One the 3rd layer of file, On the layer (i+1)st layer of Hidden layer
        inputfile >> line;
        int numNeurons = 0;
        string activation;
        line.erase(0,2);
        stringstream x(line.substr(0,line.find(':')));
        x >> numNeurons;
        line.erase(0,line.find(':')+1);
        activation = line;
        ///////////////////////////
        inputNeurons = new HiddenNeuron*[numNeurons];
       

        ////////////////////////////
        for (int j = 0; j < numNeurons;j++)   
        {
            weights = new double[prevLayerSize];
            for (int k = 0; k < prevLayerSize;k++)
            {
                inputfile >> weights[k];
            }
            inputNeurons[j] = new HiddenNeuron(prevLayerSize,weights);
            weights = NULL;

        }
        getline(inputfile,line);
        this->hiddenLayers[i] = new HiddenLayer(numNeurons, inputNeurons, activation);
        //this->hiddenLayers[i]->setNeurons(inputNeurons);
        inputNeurons = NULL;
        prevLayerSize = numNeurons;
   }


    OutputLayer:
    getline(inputfile,line);//line now on o:
    //cout << prevLayerSize << endl;
    
    weights = new double[prevLayerSize];
    for (int j = 0; j < prevLayerSize;j++)
    {
        inputfile >> weights[j];
    }

    this->outputLayer = new OutputLayer(prevLayerSize, weights);
    weights = NULL;
    // delete [] weights;
}

NeuralNetwork::~NeuralNetwork()
{
    delete inputLayer;
    inputLayer = NULL;
    delete outputLayer;
    outputLayer = NULL;
    for (int i = 0; i < numHiddenLayers; i++)
    {
        delete hiddenLayers[i];
    }
    delete [] hiddenLayers;
    hiddenLayers = NULL;
}

double NeuralNetwork::forward(double *input)
{
    inputLayer->setInputs(input);
    hiddenLayers[0]->forward(inputLayer);
    for (int i = 0; i < (numHiddenLayers -1); i++)
    {
        hiddenLayers[i+1]->forward(hiddenLayers[i]);
    }
    outputLayer->forward(hiddenLayers[numHiddenLayers-1]);
    return outputLayer->getOutputValue();
}

void NeuralNetwork::printNetwork()
{
    this->inputLayer->printLayer();
    for (int i = 0; i < this->numHiddenLayers; i++)
    {
        this->hiddenLayers[i]->printLayer();
    }
    this->outputLayer->printLayer();
}

void NeuralNetwork::clearNetwork()
{
    this->inputLayer->clearLayer();
    for (int i = 0; i < this->numHiddenLayers; i++)
    {
        this->hiddenLayers[i]->clearLayer();
    }
    this->outputLayer->clearLayer();   
}


