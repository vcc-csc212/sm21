#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

class BinarySearch {
    private:
        static int binary_search(int data, int start_idx, int end_idx, int *arr);

    public:
        //returns index of data in arr or -1 if data is not present
        static int binary_search(int data, int *arr, int len);
};

// Curious about the static keyword? Read about it: https://www.geeksforgeeks.org/static-keyword-cpp/

#endif