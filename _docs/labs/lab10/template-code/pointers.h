#ifndef POINTERS_H
#define POINTERS_H

#include <string>

class Pointers {
    public:
        // Makes ends contain the first and last elements of arr. arr should not be modified.
        static void bookends(const std::string* arr, int len, std::string (&ends)[2]);
        
        // Takes in a pointer to an array of strings, arr, an index to replace, idx, and the string it should be replaced with, str. 
        // Replaces the value in arr at idx with str. You may assume i will be within bounds, that is, assume that idx is non-negative and is not bigger than the arr’s last index.
        static void switcharoo(std::string* arr, int idx, std::string str);
};

// Curious about the static keyword? Read about it: https://www.geeksforgeeks.org/static-keyword-cpp/

#endif
