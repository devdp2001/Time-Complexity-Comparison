all: main.o experiment.o Sorting.o
	g++ -o main main.o Sorting.o
	g++ -o experiment experiment.o Sorting.o

main.o: main.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors main.cpp

experiment.o: experiment.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors experiment.cpp

Sorting.o: Sorting.h Sorting.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors Sorting.cpp

clean:
	rm -f main
	rm -f experiment
	rm -f *.o
