#include <iostream>
#include <algorithm>

#include "sorting-lab.h"

sorts::sorts() {
    //nothing to do here
}

sorts::~sorts() {
    //nothing to do here
}

//does sorting, using selection sort algo
void sorts::selectionSort(int * unsortedArr, int arrSize) {
	
	// Set the current sorted_pos to 0
	for (int sorted_pos = 0; sorted_pos <= arrSize - 1; sorted_pos++)
	{
		int smallest_elem_pos = sorted_pos; //keeping track of smallest position's index rather than value so it's easier to swap
	
		// Find the smallest element in the rest of list
		for (int i = 0; i < arrSize; i++)
		{
			if (unsortedArr[i] < unsortedArr[smallest_elem_pos])
			{
				smallest_elem_pos = i;
			}
		}

		// Swap the smallest element in the list with the element at sorted_pos
		std::swap(unsortedArr[smallest_elem_pos], unsortedArr[sorted_pos]);

		// Increment sorted_pos by 1 (done by loop)
		// Repeat 2-4 until list is sorted (until sorted_pos is n-1) (done by loop)
	}
}

//does sorting, using insertion sort algo
void sorts::insertionSort(int * unsortedArr, int arrSize) {
	// Start at the front of the list
	for (int i = 1; i < arrSize; i++) //starting at one so there's something to the left
	{
		int curr = unsortedArr[i];
		int j; //declaring outside so we can use it outside of for loop

		// Compare the current element to the element immediately to its left 
		// If the current element is smaller than the element immediately to its left...
		// ...compare the current element to all the other elements to the left
		// Do this until the current element is not smaller than the element its being compared to
		for (j = i-1; j >= 0 && curr < unsortedArr[j]; j--) //notice how the value check and iteration are both conditions in this loop
		{
			// Shift all greater values 1 space to the right
			unsortedArr[j+1] = unsortedArr[j];
		}
		// Insert the current element at the gap left from shifting
		unsortedArr[j] = curr;
	}	
}

void sorts::print(int data[], int n, std::ostream& os) {
    for(int i=0;i<n;i++)
        os << data[i] << " ";
}