# -*- MakeFile -*-

all: corridor

corridor: func.o main-c.o
	g++ main-c.o func.o

main-c.o: main-c.cpp func.h
	g++ -c main-c.cpp

func.o: func.cpp func.h
	g++ -c func.cpp


clear:
	rm -f *.o corridor