CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g 

BinarySearchTree: BinarySearchTree.o BinaryNode.o BSTPathTest.o
	$(CXX) $(DEBUG) BinarySearchTree.o BinaryNode.o BSTPathTest.o 
	@echo 


BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h



.PHONY: clean
clean:
	-rm -f *.o a.out

