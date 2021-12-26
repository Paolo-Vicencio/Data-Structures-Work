CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11 -O2 # Enable all warnings
DEBUG=-g 

topological: topological.o middleearth.o 
	$(CXX) $(DEBUG) topological.o middleearth.o 
	@echo 


middleearth.o: middleearth.cpp middleearth.h



.PHONY: clean
clean:
	-rm -f *.o a.out