#include "intbst.h"

#include <iostream>
using namespace std;

void testSuccessor(IntBST<int>&, int value, int expected);
void testPredecessor(IntBST<int>&, int value, int expected);
void testContains(IntBST<int>&, int);
void testRemove(IntBST<int>&, int);

int main() {

	IntBST<float> p1;

	p1.insert(7.5);
	p1.insert(22);
	p1.insert(83);
	p1.insert(42);
	p1.insert(-20);
	p1.insert(0);
	p1.insert(256);
	p1.insert(1);
	p1.insert(100);
	p1.insert(-10);

	cout << "Print Ordered:" << endl;
	p1.printInOrder();
	cout << endl;
	cout << "Expected:" << endl;
	cout << "-20 -10 0 1 7 22 42 83 100 256" << endl;
	cout << endl;

	cout << "Sum:" << endl;
	cout << p1.sum() << endl;
	cout << "Expected:" << endl;
	cout << "481" << endl;
	cout << endl;

	cout << "Count:" << endl;
	cout << p1.count() << endl;
	cout << "Expected:" << endl;
	cout << "10" << endl;
	cout << endl;

	//cout << "Test Successor Function: " << endl;
	//testSuccessor(p1, 7, 22);
	//testSuccessor(p1, -20, -10);
	//testSuccessor(p1, 256, 0);
	//cout << endl;

	//cout << "Test Predecessor Function: " << endl;
	//testPredecessor(p1, 0, -10);
	//testPredecessor(p1, 83, 42);
	//testPredecessor(p1, -20, 0);
	//cout << endl;

	//cout << "Test Contains Function: " << endl;
	//testContains(p1, 7);
	//testContains(p1, 6);
	//testContains(p1, -21);
	//testContains(p1, -20);
	//testContains(p1, 0);
	//cout << endl;

	//cout << "Test Remove Function: " << endl;
	//cout << "Original: " << endl;
	//p1.printInOrder();
	//cout << endl;
	//testRemove(p1, 7);
	//testRemove(p1, 256);
	//testRemove(p1, -20);
	//testRemove(p1, 22);


	return 0;
}


void testSuccessor(IntBST<int>& p, int value, int expected) {
	cout << "Successor of " << value << ":" << endl;
	cout << p.getSuccessor(value) << endl;
	cout << "Expected:" << endl;
	cout << expected << endl;
}
void testPredecessor(IntBST<int>& p, int value, int expected) {
	cout << "Predecessor of " << value << ":" << endl;
	cout << p.getPredecessor(value) << endl;
	cout << "Expected:" << endl;
	cout << expected << endl;
}
void testContains(IntBST<int>& p, int value) {
	cout << "Contains value " << value << ": ";
	if (p.contains(value)) {
		cout << "Y" << endl;
	}
	else {
		cout << "N" << endl;
	}
}

void testRemove(IntBST<int>& p, int value) {
	cout << "Removing " << value << endl;
	p.remove(value);
	cout << "Result:" << endl;
	p.printInOrder();
	cout << endl;
}