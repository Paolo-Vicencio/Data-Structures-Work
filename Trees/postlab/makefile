CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g 

BinarySearchTree: AVLTree.o AVLNode.o AVLPathTest.o
	$(CXX) $(DEBUG) AVLTree.o AVLNode.o AVLPathTest.o 
	@echo 


BinarySearchTree.o: AVLTree.cpp AVLTree.h AVLNode.h

BinaryNode.o: AVLNode.cpp AVLNode.h

BSTPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h



.PHONY: clean
clean:
	-rm -f *.o a.out
