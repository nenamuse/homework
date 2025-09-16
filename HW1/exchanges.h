#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~LinkedList() {
        clear();
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Insert at end
    void insert(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Check if a value is already in list
    bool contains(const T& value) const {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    int size() const {
        return length;
    }

    // Convert to "a, b, c" string
    string toString() const {
        stringstream ss;
        Node* curr = head;
        while (curr != nullptr) {
            ss << curr->data;
            if (curr->next != nullptr) {
                ss << ", ";
            }
            curr = curr->next;
        }
        return ss.str();
    }
};

#endif
