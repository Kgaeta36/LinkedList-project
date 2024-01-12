 /**
This is base code for Project 2 for CST238 Fall 2020
This file DOES need to be modified and handed in
ONLY RECURSION can be used; any iteration will result
in a zero for the assignment
*/
/****
Title: Project2.cpp
Abstract: This program will implement a linked list with the big three functions using exclusively recusrsive functions.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Date: 5/1/2023
Estimate: 5 hours
  ****/
#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
* Implement these functions IN ORDER
*/

// implement these two first
bool Node::hasNext() const {
    return myNext != nullptr;
}

bool LinkedList::empty() const {
  return myFirst == nullptr;
}

// then these two
void Node::display() const {
  cout << myData << " ";
  if(hasNext()){
    myNext->display();
  }
}

void LinkedList::display() const {
  if (empty()){
    cout << "Empty!" << endl;
    return;
  } else {
    myFirst->display();
    cout << endl;
  }
}

// then these two
// only append if this is the last node
// otherwise, recurse
void Node::append(int data) {
  if(hasNext()){
    myNext->append(data);
  } else {
    myNext = new Node(data);
   
  }
}

void LinkedList::append(int data) {
  if(empty()){
    myFirst = new Node(data);
  } else {
    myFirst->append(data);
  }
}

// then these two
bool Node::search(int data) const {
    if (myData == data){
      return true;
    } else if (hasNext()){
      return myNext->search(data);
    } else {
     return false;
    }
  
}

bool LinkedList::search(int data) const {
    if(empty()){
      return false;
    } else {
      return myFirst->search(data);
    }
}

// then these two
bool Node::insertAfter(int oldData, int newData) {
    if(myData == oldData){
      Node * temp = new Node(newData);
      temp->setNext(myNext);
      myNext = temp;
      return true;
    } else if (hasNext()) {
      return myNext->insertAfter(oldData, newData);
    } else{
      return false;
    }
}

bool LinkedList::insertAfter(int oldData, int newData) {
   if(empty()){
     return false;
   } else {
     return myFirst->insertAfter(oldData, newData);
   }
}

// then these two
bool Node::removeNext(int data) {
  if (myNext == nullptr){
    return false;
  } else if (myNext->getData() == data){
    Node * temp = myNext;
    myNext = myNext->getNext();
    temp->setNext(nullptr);
    delete temp;
    return true;
  } else if (hasNext()) {
    return myNext->removeNext(data);
  }else{
    return false;
  }
}

bool LinkedList::remove(int data) {
  if (empty()){
    return false;
  } else {
    return myFirst->removeNext(data);
  }
}

// then these two
Node::~Node() {
  delete myNext;
}

LinkedList::~LinkedList() {
  delete myFirst;
}

// then these two
Node::Node(const Node & source) {
  myData = source.myData;
  if(source.myNext == nullptr){
     myNext = nullptr;
  } else {
   myNext = new Node(*(source.myNext));
  }
}

LinkedList::LinkedList(const LinkedList & source) {
  if (source.myFirst == nullptr){
    myFirst = nullptr;
  } else {
    myFirst = new Node (*(source.myFirst));
  }
}

// then this one
LinkedList &LinkedList::operator=(const LinkedList & source) {
    if (this != &source){
      delete myFirst;
      if (source.myFirst == nullptr){
        myFirst = nullptr;
      } else { 
        myFirst = new Node(*(source.myFirst));
      }
    }
  return * this;
}

/**
* Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!
*/

Node::Node(int data) {
    myData = data;
    myNext = nullptr;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}

