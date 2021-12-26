CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g 

heap: heap.o heapNode.o huffmanenc.o
	$(CXX) $(DEBUG) heap.o heapNode.o huffmanenc.o 
	@echo 

heap.o: heap.cpp heap.h heapNode.h

heapNode.o: heapNode.cpp heapNode.h

huffmanenc.o: huffmanenc.cpp heap.h heapNode.h


.PHONY: clean
clean:
	-rm -f *.o a.out