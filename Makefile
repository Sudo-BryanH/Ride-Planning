
all: main.o
	g++ main.o -o planride

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o output
