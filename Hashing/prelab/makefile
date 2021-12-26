CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g 

wordPuzzle: wordPuzzle.o hashTable.o timer.o
	$(CXX) $(DEBUG) wordPuzzle.o hashTable.o timer.o
	@echo 


wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

hashTable.o: hashTable.h

timer.o: timer.h



.PHONY: clean
clean:
	-rm -f *.o a.out