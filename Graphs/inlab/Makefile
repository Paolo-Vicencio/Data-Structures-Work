CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11 -O2 # Enable all warnings
DEBUG=-g 

traveling: traveling.o middleearth.o 
	$(CXX) $(DEBUG) traveling.o middleearth.o 
	@echo 

traveling.o: traveling.cpp middleearth.h

middleearth.o: middleearth.cpp middleearth.h



.PHONY: clean
clean:
	-rm -f *.o a.out