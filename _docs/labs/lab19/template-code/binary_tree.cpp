#include "binary_tree.h"

// Constructor provided for you
BinaryTree::BinaryTree() {
    this->_root = nullptr;
}

/*********************** BEGIN: Public functions provided for you ***********************/
void BinaryTree::insert(int parent_data, int new_data){
    if(this->_root == nullptr){
        this->_root = new Node(new_data);
    } else{
        insert(parent_data, new_data, this->_root);
    }
}

bool BinaryTree::search(int data){
    return search(data, this->_root);
}

void BinaryTree::display_in_order(std::ostream& os){
    os << "In-Order: ";
    display_in_order(this->_root);
    os << std::endl;
}

void BinaryTree::display_post_order(std::ostream& os){
    os << "Post-Order: ";
    display_post_order(this->_root);
    os << std::endl;
}

void BinaryTree::display_pre_order(std::ostream& os){
    os << "Pre-Order: ";
    display_pre_order(this->_root);
    os << std::endl;
}

/*********************** END: Public functions provided for you ***********************/

/*********************** BEGIN: Private Helper Functions for you to implement ***********************/

// The whole point of this function is to search for 'parent_data' and return true once the function is done
bool BinaryTree::insert(int parent_data, int new_data, Node* curr){
    // Remember-- this is a recursive function. What should the base case be? HINT: What're we using to traverse the tree?

    
    /* 
        If we find 'parent_data', 
            insert at the left ONLY IF there's no child already there, 
            otherwise insert at the right ONLY IF there's no child already there
            IF BOTH sides have a child, the node is full and we cannot insert, exit the function.
        Otherwise, recursively search (by way of insert) for 'parent_data' to the left, if still not found, recursively search (by way of insert) to the right
    
    */

}

// The whole point of this function is to search for 'parent_data' and return true IF it finds it
bool BinaryTree::search(int data, Node* curr){

    // Remember-- this is a recursive function. What should the base case be? HINT: What're we using to traverse the tree?

    
    /* 
        If we find 'parent_data', return true
        Otherwise, search for 'parent_data' to the left, if still not found, search to the right
    
    */
}

void BinaryTree::display_in_order(Node* curr, std::ostream& os){
    /*
        Traverse left
        Visit (print) Root
        Traverse right
    */
}

void BinaryTree::display_post_order(Node* curr, std::ostream& os){
    /*
        Traverse left
        Traverse right
        Visit (print) Root
    */
}

void BinaryTree::display_pre_order(Node* curr, std::ostream& os){
    /*
        Visit (print) Root
        Traverse left
        Traverse right
    */
}

/*********************** END: Private Helper Functions for you to implement ***********************/