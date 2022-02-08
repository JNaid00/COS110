ofiles = main.o Babushka.o BlueBabushka.o Controller.o ControllerException.o DarkBlueBabushka.o DisplacementException.o GoldBabushka.o GreenBabushka.o LightBlueBabushka.o OverflowException.o RedBabushka.o RotateException.o UnderflowException.o YellowBabushka.o
line = g++ -c -std=c++98 -static

main: $(ofiles)
	g++ -std=c++98 -static $(ofiles) -o main
    
main.o: main.cpp Controller.h ControllerException.h ReturnStruct.h
	$(line) main.cpp
    
Babushka.o: Babushka.h Babushka.cpp
	$(line) Babushka.cpp
    
BlueBabushka.o: BlueBabushka.h BlueBabushka.cpp Babushka.h
	$(line) BlueBabushka.cpp

Controller.o: Controller.h Controller.cpp ControllerException.h DarkBlueBabushka.h LightBlueBabushka.h RedBabushka.h GreenBabushka.h YellowBabushka.h GoldBabushka.h ReturnStruct.h Babushka.h BabushkaException.h
	$(line) Controller.cpp

ControllerException.o: ControllerException.h ControllerException.cpp BabushkaException.h
	$(line) ControllerException.cpp

DarkBlueBabushka.o: DarkBlueBabushka.h DarkBlueBabushka.cpp UnderflowException.h OverflowException.h BlueBabushka.h
	$(line) DarkBlueBabushka.cpp

DisplacementException.o: DisplacementException.h DisplacementException.cpp BabushkaException.h
	$(line) DisplacementException.cpp

GoldBabushka.o: GoldBabushka.h GoldBabushka.cpp UnderflowException.h OverflowException.h Babushka.h
	$(line) GoldBabushka.cpp

GreenBabushka.o: GreenBabushka.h GreenBabushka.cpp DisplacementException.h Babushka.h
	$(line) GreenBabushka.cpp

LightBlueBabushka.o: LightBlueBabushka.h LightBlueBabushka.cpp UnderflowException.h OverflowException.h BlueBabushka.h
	$(line) LightBlueBabushka.cpp

OverflowException.o: OverflowException.h OverflowException.cpp BabushkaException.h
	$(line) OverflowException.cpp

RedBabushka.o: RedBabushka.h RedBabushka.cpp RotateException.h Babushka.h
	$(line) RedBabushka.cpp

RotateException.o: RotateException.h RotateException.cpp BabushkaException.h
	$(line) RotateException.cpp

UnderflowException.o: UnderflowException.h UnderflowException.cpp BabushkaException.h
	$(line) UnderflowException.cpp

YellowBabushka.o: YellowBabushka.h YellowBabushka.cpp Babushka.h
	$(line) YellowBabushka.cpp

run: main
	./main

clear:
	rm *.o main
	clear
    
clean:
	rm *.o main