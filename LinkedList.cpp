#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = 0; i < len; i++) {
        insertPosition(i+1, array[i]);
    }
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (!head || pos <= 1) {
        newNode->setLink(head);
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->getLink();
        }
        newNode->setLink(temp->getLink());
        temp->setLink(newNode);
    }
}

bool LinkedList::deletePosition(int pos) {
    if (!head) return false;
    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    } else {
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->getLink();
        }
        if (!temp || !temp->getLink()) return false;
        Node* toDelete = temp->getLink();
        temp->setLink(toDelete->getLink());
        delete toDelete;
        return true;
    }
}

int LinkedList::get(int pos) const {
    Node* temp = head;
    for (int i = 1; temp && i < pos; i++) {
        temp = temp->getLink();
    }
    if (!temp) return std::numeric_limits<int>::max();
    return temp->getData();
}

int LinkedList::search(int target) const {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->getData() == target) return pos;
        temp = temp->getLink();
        pos++;
    }
    return -1;
}

void LinkedList::printList() const {
    std::cout << "[";
    Node* temp = head;
    while (temp) {
        std::cout << temp->getData();
        temp = temp->getLink();
        if (temp) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}
