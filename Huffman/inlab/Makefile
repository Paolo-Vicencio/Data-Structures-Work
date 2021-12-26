CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g 

heap: heap.o heapNode.o huffmandec.o
	$(CXX) $(DEBUG) heap.o heapNode.o huffmandec.o 
	@echo 

heap.o: heap.cpp heap.h heapNode.h

heapNode.o: heapNode.cpp heapNode.h

huffmanenc.o: huffmandec.cpp heap.h heapNode.h


.PHONY: clean
clean:
	-rm -f *.o a.out