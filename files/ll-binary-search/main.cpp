#include "LinkedList.h"
#include <iostream>

int main(){
    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    if (ll.binary_search(3) != 2) {
        std::cout << "Binary search isn't working when element IS present.\n";
    }

    if (ll.binary_search(13) != -1) {
        std::cout << "Binary search isn't working when element is NOT present.\n";
    }

    if (ll.binary_search(0) != -1) {
        std::cout << "Binary search isn't working when element is NOT present.\n";
    }
}