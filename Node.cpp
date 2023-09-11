#include "Node.h"

Node::Node(int data) : data(data), link(nullptr) {}

int Node::getData() const {
    return data;
}

void Node::setData(int data) {
    this->data = data;
}

Node* Node::getLink() const {
    return link;
}

void Node::setLink(Node* link) {
    this->link = link;
}
