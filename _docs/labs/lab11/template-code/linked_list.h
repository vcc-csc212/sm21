#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <string>

class LinkedList{
    private:
        Node* head;

        // Having a tail pointer is optional. It simplifies some functions at the cost of you having to keep track of it.
        Node* tail; // Comment out if NOT using
        
        // It's good practice to keep track of the size of the list so you don't have to iterate through and calculate it later
        unsigned int _size = 0;

    public:
        LinkedList();

        // Adds a character to the front of the list. 
        void push_front(char data);
        // Adds a character to the end of the list. 
        void push_back(char data);
        // Adds a character to the list at a specific index. 
        void insert(char data, unsigned int idx);
        // Searches for & removes a specific element in the list. 
        void del(char data);
        // Returns true if the given value exists in the list. False otherwise.
        bool contains(char data);
        // Returns the total number of elements in the list
        int size();
        // Converts the list into a printable string-- useful for testing . The list c -> o -> d -> e would return "c o d e "
        std::string to_string();
};

#endif