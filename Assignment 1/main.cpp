#include "InputLayer.h"
#include "NeuralNetwork.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
	NeuralNetwork test("x_squared.txt");
    double *inputs = new double[1];
    // inputs[0] = 5.0;
    // inputs[1] = 10.0;
    // inputs[2] = 15.0;
    // inputs[3] = 20.0;
    // inputs[4] = 25.0;

    inputs[0] = 8.0;
    // inputs[1] = -2.0;
    // inputs[2] = -3.0;
    // inputs[3] = -4.0;
    // inputs[4] = -5.0;
   cout << test.forward(inputs) << endl;
    //test.printNetwork();
  // test.clearNetwork();
    // InputLayer test(3);
    // double *testinput = new double[3];
    // testinput[0] = 0;
    // testinput[1] = 1;
    // testinput[2] = 2;
    // //cout <<   testinput[2];
    // //cout << testinput;
    // test.setInputs(testinput);
    // test.setInputs(testinput);

    return 0;
}
