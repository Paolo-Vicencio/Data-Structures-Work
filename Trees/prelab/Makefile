CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g 

binaryHeap: binaryHeap.o heapNode.o huffmanenc.o
	$(CXX) $(DEBUG) binaryHeap.o heapNode.o huffmanenc.o 
	@echo 

binaryHeap.o: binaryHeap.cpp binaryHeap.h heapNode.h

heapNode.o: heapNode.cpp heapNode.h

huffmanenc.o: huffmanenc.cpp binaryHeap.h heapNode.h


.PHONY: clean
clean:
	-rm -f *.o a.out