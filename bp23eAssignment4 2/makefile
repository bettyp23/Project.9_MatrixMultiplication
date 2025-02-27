# makefile for matrix multiplication
# Betty Phipps
# Date: 03/24/25
# Make -> ./main

# name of executable
main: main.o matrix.o
	g++ $(CXXFLAGS) main.o matrix.o -o main

main.o: main.cpp matrix.h
	g++ $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.h
	g++ $(CXXFLAGS) -c matrix.cpp

clean: 
	rm -rf *.o main

CXXFLAGS = -std=c++11