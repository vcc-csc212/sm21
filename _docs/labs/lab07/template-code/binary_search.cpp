#include "binary_search.h"
#include <iostream>

int BinarySearch::binary_search(int data, int start_idx, int end_idx, int *arr) {

 	//NOTE: you an solve this iteratively or recursively! Up to you :)

	//calculate midpoint
	//compare midpoint to data
	//if equal we're done and can return where we're at since we found the index
	//if midpoint is bigger then we should search in the first half of where we're at
	//if midpoint is smaller then we should search in the last half of where we're at
}

int BinarySearch::binary_search(int data, int *arr, int len) {
	return binary_search(data, 0, len-1, arr);
}