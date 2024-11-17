CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

all: test

test: TestSubsetSum.o SubsetSum.o
	$(CXX) $(CXXFLAGS) -o test TestSubsetSum.o SubsetSum.o

SubsetSum.o: src/SubsetSum.cpp src/SubsetSum.h
	$(CXX) $(CXXFLAGS) -c src/SubsetSum.cpp

TestSubsetSum.o: src/TestSubsetSum.cpp src/SubsetSum.h
	$(CXX) $(CXXFLAGS) -c src/TestSubsetSum.cpp

clean:
	rm -f *.o test
