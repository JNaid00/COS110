oFiles = main.o piece.o
gpp_o = g++ -c -g -std=c++98 -static

main: $(oFiles)
	g++ -std=c++98 -static $(oFiles) -o main

main.o: main.cpp piece.h
	$(gpp_o) main.cpp

piece.o: piece.cpp piece.h
	$(gpp_o) piece.cpp

run: main
	./main

clean:
	rm *.o main
