//
// Created by Erica Quintero on 9/24/25.
//

#pragma once
#include <iostream>
using namespace std;
//initialized the struct to take on different variable types
template <typename T>
struct Node {
    T value;

    Node<T>* next;
    Node<T>* prev;

    Node(T val, Node<T>* nxt = nullptr, Node<T>* prv = nullptr) {
        value = val;
        next = nxt;
        prev = prv;
    }

};

template <typename T>
class Interactions {

public:
    //default constructor
    Interactions() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~Interactions() { //destructor
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
//Insert at the end so tracker wont get cluttered
void InsertEnd(){
    
}

 //tracks the interactions
void Tracker(T value){ // mutator function
    //how do we track interactions? 
    Node<T>* 
}

//if A had mety B return true 
//bool hasMet

//Print those who won
//void Print



private:
    Ppl<T>* head;
    Ppl<T>* tail;
    int size;
};

