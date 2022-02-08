oFiles = main.o InputLayer.o HiddenNeuron.o HiddenLayer.o OutputLayer.o NeuralNetwork.o
gpp_o = g++ -c -g -std=c++98 -static

main: $(oFiles)
	g++ -std=c++98 -static $(oFiles) -o main

main.o: main.cpp InputLayer.h
	$(gpp_o) main.cpp

InputLayer.o: InputLayer.cpp InputLayer.h
	$(gpp_o) InputLayer.cpp

HiddenNeuron.o: HiddenNeuron.cpp HiddenNeuron.h InputLayer.h HiddenLayer.h
	$(gpp_o) HiddenNeuron.cpp

HiddenLayer.o: HiddenLayer.cpp HiddenLayer.h InputLayer.h HiddenNeuron.h
	$(gpp_o) HiddenLayer.cpp

OutputLayer.o: OutputLayer.cpp OutputLayer.h HiddenLayer.h
	$(gpp_o) OutputLayer.cpp

NeuralNetwork.o: NeuralNetwork.cpp NeuralNetwork.h HiddenNeuron.h HiddenLayer.h OutputLayer.h InputLayer.h
	$(gpp_o) NeuralNetwork.cpp

run: main
	./main

clean:
	rm *.o main
