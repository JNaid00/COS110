#ifndef INPUTLAYER_H
#define INPUTLAYER_H

//using namespace std;

class InputLayer
{
    private:
        int numInputs;
        double* inputs;
    public:
        InputLayer(int numInputs); //Constructor
        ~InputLayer();             //Destructor

        double *getInputs();
        int getNumInputs();
        void setInputs(double* inputs);
        void setNumInputs(int numInputs);
        void printLayer();
        void clearLayer();

};
#endif
