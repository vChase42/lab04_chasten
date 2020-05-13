// intbst.cpp
// Implements class IntBST
// Chase Alcorn, 4/30/2020

#include "intbst.h"

#include <iostream>
using namespace std;





// constructor sets up empty tree
template <typename T>
IntBST<T>::IntBST() : root(0) {}

// destructor deletes all nodes
template <class T>
IntBST<T>::~IntBST(){
    clear(root);
}

// recursive helper for destructor
template <class T>
void IntBST<T>::clear(Node *n){
    if (n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
template <class T>
bool IntBST<T>::insert(T value){
    // handle special case of empty tree first
    if (!root){
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
template <class T>
bool IntBST<T>::insert(T value, Node *n){
    if (value == n->info)
        return false;
    if (value < n->info){
        if (n->left){
            return insert(value, n->left);
        }
        else{
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else
    {
    if (n->right) {
        return insert(value, n->right);
    }
    else
    {
        n->right = new Node(value);
        n->right->parent = n;
        return true;
    }
    }
}

// print tree data pre-order
template <class T>
void IntBST<T>::printPreOrder() const
{
    printPreOrder(root);
}

// recursive helper for printPreOrder()
template <class T>
void IntBST<T>::printPreOrder(Node* n) const
{
    if (n) {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
template <class T>
void IntBST<T>::printInOrder() const {
    printInOrder(root);
}

template <class T>
void IntBST<T>::printInOrder(Node* n) const {
    // IMPLEMENT HERE
    if (n) {
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
template <class T>
void IntBST<T>::printPostOrder() const {
    printPostOrder(root);
}

template <class T>
void IntBST<T>::printPostOrder(Node* n) const {
    // IMPLEMENT HERE
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
}

// return sum of values in tree
template <class T>
T IntBST<T>::sum() const {
    return sum(root);
}

// recursive helper for sum
template <class T>
T IntBST<T>::sum(Node* n) const {
    if (n) {
        return sum(n->left) + sum(n->right) + n->info;
    }
    else {
        return T(0);
    }
}

// return count of values
template <class T>
int IntBST<T>::count() const {
    return count(root);
}

// recursive helper for count
template <class T>
int IntBST<T>::count(Node* n) const {
    if (n) {
        return count(n->left) + count(n->right) + 1;
    }
    return 0;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
template <class T>
typename IntBST<T>::Node* IntBST<T>::getNodeFor(typename T value, Node* n) const {
    if (!n) {
        return NULL;
    }

    if (value < n->info) {
        return getNodeFor(value, n->left);
    }
    else if(value > n->info){
        return getNodeFor(value, n->right);
    }
    else {
        return n;
    }
}

// returns true if value is in the tree; false if not
template <class T>
bool IntBST<T>::contains(T value) const{
    if (getNodeFor(value, root) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

// returns the Node containing the predecessor of the given value
template <class T>
typename IntBST<T>::Node *IntBST<typename T>::getPredecessorNode(typename T value) const{
    Node* tmp = getNodeFor(value, root);
    if (tmp) {
        if (tmp->left) {
            tmp = tmp->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            return tmp;
        }
        while (tmp->parent) {
            tmp = tmp->parent;
            if (value > tmp->info) {
                return tmp;
            }
        }
    }
    return NULL;
}

// returns the predecessor value of the given value or 0 if there is none
template <class T>
T IntBST<T>::getPredecessor(T value) const{
    Node* tmp = getPredecessorNode(value);
    if (tmp) {
        return tmp->info;
    }
    return 0;
}

// returns the Node containing the successor of the given value
template <class T>
typename IntBST<T>::Node *IntBST<typename T>::getSuccessorNode(typename T value) const{
    Node* tmp = getNodeFor(value, root);
    if (tmp) {
        if (tmp->right) {
            tmp = tmp->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            return tmp;
        }
        while (tmp->parent) {
            tmp = tmp->parent;
            if (value < tmp->info) {
                return tmp;
            }
        }
    }
    return NULL;
}

// returns the successor value of the given value or 0 if there is none
template <class T>
T IntBST<T>::getSuccessor(T value) const{
    Node* tmp = getSuccessorNode(value);
    if (tmp) {
        return tmp->info;
    }
    return 0;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template <class T>
bool IntBST<T>::remove(T value){
    Node* tmp = getNodeFor(value, root);
    
    if (tmp->right) {
        Node* right = getSuccessorNode(value);
        if (tmp->left) {
            right->left = tmp->left;
            right->left->parent = right;
        }
        if (tmp == root) {
            root = tmp->right;
            tmp->right->parent = NULL;
        }
        else {
            right->parent = tmp->parent;
            if (tmp->parent->right == tmp) {
                tmp->parent->right = tmp->right;
            }
            else {
                tmp->parent->left = tmp->right;
            }
        }
        delete tmp;
        return true;
    }
    else if(tmp->left){
        Node* left = tmp->left;
        if (tmp == root) {
            root = tmp->left;
            tmp->left->parent = NULL;
        }
        else {
            left->parent = tmp->parent;
            if (tmp->parent->right == tmp) {
                tmp->parent->right = left;
            }
            else {
                tmp->parent->left = left;
            }
        }
        delete tmp;
        return true;
    }
    else if(tmp){
        if (tmp == root) {
            root = NULL;
        }
        else {
            if (tmp->parent->right == tmp) {
                tmp->parent->right = NULL;
            }
            else {
                tmp->parent->left = NULL;
            }
        }
        delete tmp;
        return true;
    }
    return false;
}

void declaration() {
    IntBST<int> i;
    IntBST<char> what;
    IntBST<double> hello;
    IntBST<float> f;
}


//int main() {
//    IntBST<double> p1;
//
//    p1.insert(7.5);
//    p1.insert(22);
//    p1.insert(83);
//    p1.insert(42);
//    p1.insert(-20);
//    p1.insert(0);
//    p1.insert(256);
//    p1.insert(1);
//    p1.insert(100);
//    p1.insert(-10);
//
//    cout << "Print Ordered:" << endl;
//    p1.printInOrder();
//    cout << endl;
//    cout << "Expected:" << endl;
//    cout << "-20 -10 0 1 7 22 42 83 100 256" << endl;
//    cout << endl;
//
//    cout << "Sum:" << endl;
//    cout << p1.sum() << endl;
//    cout << "Expected:" << endl;
//    cout << "481" << endl;
//    cout << endl;
//
//    cout << "Count:" << endl;
//    cout << p1.count() << endl;
//    cout << "Expected:" << endl;
//    cout << "10" << endl;
//    cout << endl;
//    return 0;
//}