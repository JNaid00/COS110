#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H
#include "InputLayer.h"
#include "HiddenLayer.h"
#include <string>
//using namespace std;

class HiddenLayer;

class HiddenNeuron
{
    private:
        double value;               //current value this neron holds
        int numWeights;             //Holds SIZE of weights array, value corresponds to number of neurons in previous layer
        double* weights;            //1D array, contain values of weights connecting to this nueron from the previous layer
    public:
        HiddenNeuron(int numWeights, double* weights); //sets the corresponding member variables (without deep copying the array). The value of this neuron should initially be set to zero.
        ~HiddenNeuron();            //deallocate the weights array
        double getValue();
        void setValue(double value);
        void forward(HiddenLayer* prevLayer); //calculating the new value of this neuron
                                    //multiplies the value of each neuron in the previous hidden layer by the corresponding weight in the weights array of this neuron

        void forward(InputLayer* inputLayer);
        void activateReLU();
        void activateSigmoid();

};
#endif