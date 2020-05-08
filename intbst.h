// intbst.h
// Binary search tree header file for CS 24 lab

#ifndef INTBST_H
#define INTBST_H

#include <iostream>

using namespace std;

template <class T> class IntBST{

public:
    // ctor, dtor, insert and one print method already done in intbst.cpp:
    IntBST();                   // constructor
    ~IntBST();                  // destructor
    bool insert(T value);     // insert value; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout

    // 8 METHODS YOU MUST IMPLEMENT in intbst.cpp:
    void printInOrder() const;      // print tree data in-order to cout
    void printPostOrder() const;    // print tree data post-order to cout
    T sum() const;                // sum of all values
    int count() const;              // count of values
    bool contains(T value) const; // true if value is in tree

    // THESE ARE HARDER! DO THESE LAST
    T getPredecessor(T value) const; // returns the predecessor value of the given value or 0 if there is none
    T getSuccessor(T value) const;   // returns the successor value of the given value or 0 if there is none
    bool remove(T value);              // deletes the Node containing the given value from the tree

private:
    template <class T>
    struct Node
    {
        T info;
        Node<T> *left, *right, *parent;
        // useful constructor:
        Node(typename T v) : info(v), left(0), right(0), parent(0) {}
    };

    // just one instance variable (pointer to root node):
    Node<T> *root;

    // recursive utility functions for use by public methods above
    Node<T> *getNodeFor(typename T value, Node<T> *n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node<T> *n);                        // for destructor
    bool insert(T value, Node<T> *n);            // note overloading names for simplicity
    void printPreOrder(Node<T> *n) const;
    void printInOrder(Node<T> *n) const;
    void printPostOrder(Node<T> *n) const;
    T sum(Node<T> *n) const;
    int count(Node<T> *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node<T> *getSuccessorNode(typename T value) const;   // returns the Node containing the successor of the given value
    Node<T> *getPredecessorNode(typename T value) const; // returns the Node containing the predecessor of the given value
};

#include "intbst.cpp"

#endif
