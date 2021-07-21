#include "heap.h"

// HeapNode Class provided for you
HeapNode::HeapNode(int data){
    this->m_data = data;
    this->m_left = nullptr;
    this->m_right = nullptr;
}

HeapNode::~HeapNode(){

}

/*********************** BEGIN: Public Heap functions provided for you ***********************/

HeapTree::HeapTree(){
    this->m_root = nullptr;
}

HeapTree::~HeapTree(){
    destroy(this->m_root);
}

void HeapTree::insert(int data){
    this->m_root = insert(data, this->m_root);
}

int HeapTree::height(){
    return height(this->m_root);
}

void HeapTree::preorder(std::ostream& os){
    os << "Pre-Order: ";
    preorder(this->m_root, os);
    os << "\n";
}

void HeapTree::inorder(std::ostream& os){
    os << "In-Order: ";
    inorder(this->m_root, os);
    os << "\n";
}

void HeapTree::postorder(std::ostream& os){
    os << "Post-Order: ";
    postorder(this->m_root, os);
    os << "\n";
}

bool HeapTree::search(int data){
    return search(data, this->m_root);
}

bool HeapTree::isFull(){
    return isFull(this->m_root);
}

bool HeapTree::isComplete(){
    return isComplete(this->m_root, 0, size(this->m_root));
}

void HeapTree::remove_min(){
    remove_min(this->m_root);
    this->m_root = min_heapify(this->m_root);
}

void HeapTree::delete_element(int data){
    delete_element(data, this->m_root);
    this->m_root = min_heapify(this->m_root);
}

// Strictly used for the test cases
void HeapTree::find_last(std::ostream& os){
    HeapNode* temp = find_last(this->m_root, 0, size(this->m_root));
    os << temp->data << std::endl;
}

/*********************** END: Public functions provided for you ***********************/

/*********************** BEGIN: Private Helper Functions for you to implement ***********************/

HeapNode* HeapTree::insert(int data, HeapNode* curr){
    // remember heaps must be complete. remember the definition of complete (hint: involves fullness)
    // this is a MIN heap so all children must be largeer than their parents

    /*
    For Insert, we need to ensure that the value being inserted goes into the correct spot in the tree. 
    As a Heap is a Complete Tree, the values are inserted in the order pursuant to the "indexing" strategy shown in the lab handout. 
    The strategy for this:

    1. If we arrive at `nullptr`, return a new Node object
    2. Compare the data being inserted to the data at the current Node
       - Swap the value being inserted with the value at the current Node if needed.
    3. If this subtree is a Full Tree with equal sized subtrees, or its left subtree is not a Full Tree
       - Insert to the left
    4. Else
       - Insert to the right
    */
}

int HeapTree::height(HeapNode* curr){
    // don't re-invent the wheel, use what you have from lab 20
}

void HeapTree::preorder(HeapNode* curr, std::ostream& os){
    // don't re-invent the wheel, use what you have from lab 20
}

void HeapTree::inorder(HeapNode* curr, std::ostream& os){
    // don't re-invent the wheel, use what you have from lab 20
}

void HeapTree::postorder(HeapNode* curr, std::ostream& os){
    // don't re-invent the wheel, use what you have from lab 20
}

void HeapTree::destroy(HeapNode* curr){
    // don't re-invent the wheel, use what you have from lab 20
}

bool HeapTree::search(int data, HeapNode* curr){
    // remember this is a MIN heap so all children must be largeer than their parents
}

bool HeapTree::isFull(HeapNode* curr){
    // don't re-invent the wheel, use what you have from lab 20
}

bool HeapTree::isComplete(HeapNode* curr, int index, int node_count){
    // don't re-invent the wheel, use what you have from lab 20
}

int HeapTree::size(HeapNode* curr){
    // don't re-invent the wheel, use what you have from lab 20
}

HeapNode* HeapTree::min_heapify(HeapNode* curr){
    // Remember heaps SWAP NOT ROTATE

    /*
    Due to the way most Heap operations work, it requires having a "fixer" function that ensures the properties of the Heap are maintained after each operation that could jeopardize them. 
    As usual for Trees, we will be doing so recursively.

    1. Check if there is a left child
        - Swap the current Node & the Node to its left, if needed.
        - Recursively continue down the left branch.
    2. Check if there is a right child
        - Swap the current Node & the Node to its right, if needed.
        - Recursively continue down the right branch.

    The end result of the Heapify function is a Tree in which the Min-Heap property is maintained.
    */
}

HeapNode* HeapTree::find_last(HeapNode* curr, int index, int node_count){
    /*
    A common operation is locating the last element in the Heap. 
    Referencing (once again) the "indexing" strategy from the lab handout, we need an algorithm to locate the right-most element in the bottom-most row of the tree. 
    For our purposes, whenever we find that Node we also want to remove it from the Tree. 
    We can use this algorithm:

    1. If we reach `nullptr` or calculate an index >= the # of Nodes we have in the tree
       - Return `nullptr`
    2. If we've located the last element in the tree
       - Return it, mark it to be removed from the Tree
    3. Search left, calculating the index for that Node
       - Handle removing the Node if necessary
    4. Search right, calculating the index for that Node
       - Handle removing the Node if necessary
     */
}

void HeapTree::remove_min(HeapNode* curr){
    /*
    Removing the Min of the Heap is a fairly common operation. Here's how we do it:

    1. Find the last Node in the tree
    2. Swap it with the Min/Max Node
    3. Delete the last Node in the tree
    4. Heapify! (Since heapfying is computationally expensive [when compared to the rest of the heap fuctions] we only do it once in the non-recursive function, i.e., in the public function, take a look above!)
    */
}

void HeapTree::delete_element(int data, HeapNode* curr){
    /*
    Another common operation, and its very similar to Remove Min!

    1. Find the Node containing the data we wish to remove
    2. Find the last Node in the tree
    3. Swap it with the Node containing our target data
    4. Delete the last Node in the tree
    5. Heapify! (Since heapfying is computationally expensive [when compared to the rest of the heap fuctions] we only do it once in the non-recursive function, i.e., in the public function, take a look above!)
    */

}

/*********************** END: Private Helper Functions for you to implement ***********************/