#include "linked_list.h"
#include <iostream>

// Do not modify the given functions. Make sure to update the size_ member variable as needed

LinkedList::LinkedList() {
	// Remember to set all member variables to something so you don't get garbage values.
}

void LinkedList::push_front(char data) {
	// Given the `head` pointer, this operation should be constant time.
	// Make sure to update the size_ member variable as needed
}

void LinkedList::push_back(char data) {
	// If using the optional `tail` pointer, this operation should be constant time. Otherwise, it will be linear.
	// Make sure to update the size_ member variable as needed
}
void LinkedList::insert(char data, unsigned int idx) {
	// You'll need to traverse through the list keeping track of what index you're at. 
	// Assume linked lists, like arrays, are 0-indexed and that the index given will exist.
	// Make sure to update the size_ member variable as needed
}

void LinkedList::del(char data) {
	// You'll need to traverse through the list until you find the specific element and you'll need to removee it without losing any other part of the list. 
	// HINT: A second temporary node may be helpful.
	// Make sure to update the size_ member variable as needed

}

bool LinkedList::contains(char data) {
	// You'll need to traverse through the list until you find the specific element or are done traveresing the list, whichever happens first.
	return false;
}

int LinkedList::size(){
    return this->_size;
}

std::string LinkedList::to_string(){
    std::string str = "";

    Node* temp = this->head;

    while(temp != nullptr){
        str += temp->data;
        str += " ";
        temp = temp->next;
    }

    return str;
}