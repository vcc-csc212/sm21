#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    this->head = nullptr;
    this->_size = 0;
}

void LinkedList::push_front(int data){
    //Simply create a new node, assign its ‘next’ to head, and assign head to the new node!
    // This will work, but its a bit clunky. We have 4 assignments instead of the 2 by using the other constructor!
    // Node* temp = new Node();
    // temp->data = data;
    // temp->next = this->head;

    // Much better implementation, only 2 assignments made & 1 line of code!
    Node* temp = new Node(data, this->head);
    this->head = temp;
    this->_size++;
}

void LinkedList::push_back(int data){
    if (this->head == nullptr) {
        this->head = new Node(data);
    } else {
        // Start temp pointer at head
        Node* temp = this->head;

        // Traverse Linked List until we arrive at the last element
        while(temp->next != nullptr){
            temp = temp->next;
        }

        // Create a new Node at the end of the list
        temp->next = new Node(data);
    }
    this->_size++;
}

void LinkedList::insert(int data, unsigned int idx){
    unsigned int curr_idx = 0;

    // Special case: Insert into beginning of list
    if(idx == 0){
        this->push_front(data);
        return;
    }

    // Special case: User input idx > size
    if(idx > this->_size){
        idx = this->_size;
    }

    // Start temp pointer at head
    Node* temp = this->head;

    // Traverse Linked List until we arrive at the last element
    while(curr_idx != idx-1){
        temp = temp->next;
        curr_idx++;
    }

    Node* new_node = new Node(data, temp->next);
    temp->next =  new_node;
    this->_size++;
}

void LinkedList::del(int data){
    // Start temp pointer at head
    Node* curr = this->head;
    Node* prev = nullptr;

    // Traverse Linked List until we arrive at 'data' OR the end of the list
    while(curr != nullptr && curr->data != data){
        prev = curr;
        curr = curr->next;
    }

    // If we found 'data'
    if(curr){
        if(curr == this->head){
            prev = curr;
            this->head = curr->next;
            delete prev;
        }else{
            prev->next = curr->next;
            delete curr;
        }
        this->_size--;
    }
}

bool LinkedList::contains(int data){
    // Start temp pointer at head
    Node* temp = this->head;

    // Traverse Linked List until we arrive at the end OR we find 'data'
    while(temp != nullptr && temp->data != data){
        temp = temp->next;
    }

    // Check if we stopped looping because we found 'data'
    if(temp){
        return true;
    }

    // We reached the end of the list & did not find 'data'
    return false;
}

int LinkedList::size(){
    return this->_size;
}

// TODO implement binary search for a linked list. 
// HINT: Will require iterating to get to the midpoint since we can't index into it
// HINT 2: You may be tempted to use contains() but it won't help much
// FOOD FOR THOUGHT: Is binary search as efficient on linked lists as it is on arrays? Why or why not?
int LinkedList::binary_search_helper(int data, int start_ix, int end_idx){
    //return index of data if it's in the list, return -1 otherwise
    return -1;
}

int LinkedList::binary_search(int data){
    return binary_search_helper(data, 0, this->_size);
}

std::string LinkedList::to_string(){
    std::string str = "";

    Node* temp = this->head;

    while(temp != nullptr){
        str += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    return str;
}