#include "Node.h"
#include <string>

class LinkedList{
    private:
        Node* head;
        unsigned int _size;
        int binary_search_helper(int data, int start_ix, int end_idx);

    public:
        LinkedList();

        void push_front(int data);
        void push_back(int data);
        void insert(int data, unsigned int idx);
        void del(int data);
        bool contains(int data);
        int size();
        int binary_search(int data);
        std::string to_string();
};