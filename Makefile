all: IntBST

IntBST: testbst.o
	g++ testbst.o -o IntBST

testbst.o: test_intbst.cpp intbst.h
	g++ -c -Wall test_intbst.cpp

clean:
	rm *.o IntBST