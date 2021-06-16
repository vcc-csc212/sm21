#ifndef NODE_H
#define NODE_H

class Node {
    private:
        char data;
        Node* next;

    public:
        Node();
        Node(char data);
        Node(char data, Node* next);

        friend class LinkedList; // Read about the `friend` keyword: https://www.educative.io/edpresso/what-is-the-friend-keyword-in-cpp.
};

#endif