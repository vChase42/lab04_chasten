all: IntBST

IntBST: bst.o testbst.o
	g++ bst.o testbst.o -o IntBST
  
bst.o: intbst.cpp intbst.h
	g++ -c -Wall intbst.cpp

testbst.o: test_intbst.cpp
	g++ -c -Wall test_intbst.cpp

clean:
	rm *.o IntBST