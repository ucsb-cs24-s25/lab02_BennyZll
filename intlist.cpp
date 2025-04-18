// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = source.head;
    tail = source.tail;
}

// destructor deletes all nodes
IntList::~IntList() {
    Node * currentNode = head;
    while(currentNode != nullptr)
    {
        Node * temp = currentNode;
        currentNode = currentNode -> next;
        delete temp;
    }
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node * currentNode = this -> head;
    while(currentNode != nullptr)
    {
        sum +=  currentNode -> info;
        currentNode = currentNode -> next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node * currentNode = this -> head;
    while(currentNode != nullptr)
    {
       if(currentNode -> info == value)
       {
        return true;
       }
       currentNode = currentNode -> next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
   int max = 0;
   Node * currentNode = this -> head;
    while(currentNode != nullptr)
    {
        if(currentNode -> info > max)
        {
            max = currentNode -> info;
        }
        currentNode = currentNode -> next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double sum = 0;
    int count = 0;
    Node * currentNode = this -> head;
    while(currentNode != nullptr)
    {
        sum += currentNode -> info;
        count ++;
        currentNode = currentNode -> next;
    }
    if(head != nullptr)
    {
        sum = sum / count;
        return sum;
    }
    else
    {
        return 0;
    }
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node * currNode = new Node();
    currNode -> info = value;
    if(head != nullptr)
    {    
        Node * temp = head;
        currNode -> next = temp;
        head = currNode;
    }
    else
    {
        head = currNode;
        tail = currNode;
        currNode -> next = nullptr;
    }

}   

// append value at end of list
void IntList::push_back(int value) {
    Node * currNode = new Node();
    currNode -> info = value;
    if(tail != nullptr)
    {
        Node * temp = tail;
        temp -> next = currNode;
        tail = currNode;
        currNode -> next = nullptr;
    }
    else
    {
        head = currNode;
        tail = currNode;
        currNode -> next = nullptr;
    }
}

// return count of values
int IntList::count() const {
   int count = 0;
   Node * currentNode = this -> head;
    while(currentNode != nullptr)
    {
        count ++;
        currentNode = currentNode -> next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this == &source)
    {
        return *this;
    }
    Node * currentNode =  head;
    while(currentNode != nullptr)
    {
        Node* prev = currentNode;
        currentNode = currentNode -> next;
        delete prev;
    }
    head = nullptr;
    tail = nullptr;
    currentNode = source.head;
    while(currentNode != nullptr)
    {
        push_back(currentNode -> info);
        currentNode = currentNode -> next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;

}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

