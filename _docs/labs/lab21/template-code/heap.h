#ifndef __HEAP__
#define __HEAP__

#include <iostream>
#include <ostream>

// Underlying class which will be used to implement the HeapTree class.
// I.E. HeapTree is made up of HeapNode
class HeapNode
{
    private:
        int m_data;
        HeapNode* m_left;
        HeapNode* m_right;

    public:
        HeapNode(int data);
        ~HeapNode();

    friend class HeapTree;
};

class HeapTree
{
    private:
        HeapNode* m_root;

        // Helper functions for public functions that also accept a HeapNode* as an argument to traverse the heap

        HeapNode* insert(int data, HeapNode* curr);
        int height(HeapNode* curr);

        void preorder(HeapNode* curr, std::ostream& os);
        void inorder(HeapNode* curr, std::ostream& os);
        void postorder(HeapNode* curr, std::ostream& os);

        void destroy(HeapNode* curr);
        bool search(int data, HeapNode* curr);

        bool isComplete(HeapNode* curr, int index, int node_count);
        bool isFull(HeapNode* curr);
        int size(HeapNode* curr);

        void remove_min(HeapNode* curr);
        void delete_element(int data, HeapNode* curr);

        HeapNode* min_heapify(HeapNode* curr);
        HeapNode* find_last(HeapNode* curr, int index, int node_count);


    public:
        HeapTree();
        ~HeapTree();

        void insert(int data);
        int height();

        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);

        bool search(int data);

        bool isComplete();
        bool isFull();

        void remove_min();
        void delete_element(int data);

        void find_last(std::ostream& os = std::cout);
};

#endif