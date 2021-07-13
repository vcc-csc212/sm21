#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <iostream>


class BinaryTree{

    struct Node{
        int m_key;
        Node* m_left;
        Node* m_right;

        Node(int data){
            this->m_key = data; 
            this->m_left = nullptr; 
            this->m_right = nullptr;
        }
    };

    private:
        Node* _root;

        // Helper functions for public functions that also accept a Node* as an argument to traverse the tree
        bool insert(int parent_data, int new_data, Node* curr);
        bool search(int data, Node* curr);
        void display_in_order(Node* curr, std::ostream& os = std::cout);
        void display_post_order(Node* curr, std::ostream& os = std::cout);
        void display_pre_order(Node* curr, std::ostream& os = std::cout);

    public:
        BinaryTree();
        // Search the Tree for the Node containing 'parent_data' and append a new Node containing 'new_data'. Prefer appending to the Left.
        void insert(int parent_data, int new_data);

        // Search the Tree for a Node containing 'data'. Returns 'true' if it exists, 'false' otherwise.
        bool search(int data);

        // Display the tree according to the rules for each traversal method outlined in the readings and handout.
        void display_in_order(std::ostream& os = std::cout);
        void display_post_order(std::ostream& os = std::cout);
        void display_pre_order(std::ostream& os = std::cout);
};

#endif