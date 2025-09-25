//
// Created by Erica Quintero on 9/24/25.
//

#pragma once
#include <iostream>
using namespace std;



//initialized the struct to take on different variable types

template <typename T>
struct Ppl {
    T value;

    Ppl<T>* next;
    Ppl<T>* prev;

    Ppl(T val, Ppl<T>* nxt = nullptr, Ppl<T>* prv = nullptr) {
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
        Ppl<T>* current = head;
        while (current != nullptr) {
            Ppl<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    //




private:
    Ppl<T>* head;
    Ppl<T>* tail;
    int size;
};

