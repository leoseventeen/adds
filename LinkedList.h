#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <limits>

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    LinkedList(int* array, int len);
    ~LinkedList();
    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos) const;
    int search(int target) const;
    void printList() const;
};

#endif
