#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

public:
    Node(int data);
    int getData() const;
    void setData(int data);
    Node* getLink() const;
    void setLink(Node* link);
};

#endif
