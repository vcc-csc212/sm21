#include <iostream>
#include "lab16.h"

void sorts::print(int data[], int n, std::ostream& os) {
	// DO NOT EDIT
    for(int i=0;i<n;i++) {
        os << data[i] << " ";
    }
}

void sorts::merge(int data[], int temp[], int low, int mid, int high) {
	for(int i=low;i<=high;i++) {
        //how do you copy an array's items to the new array temp?
	}
    //variables to track the low, middle, and high indices, we will need 3 of these
	int i = low;
	//Think about why j here has mid + 1
	int j = mid + 1;
	int k = low;

	//while we have items in left and right subarray...
	while( (i<=mid) && (j<=high) ) {
        //if left is smaller, we put it to its right/sorted position in the array.
        //write something that compares the 2 split arrays in merge, and then iterates through the split list that just added a value to the new array

	}
	//sometimes we have items left in the left subarray, so we copy it to the final nums array. They're in sorted order at this point, so we just copy them
	//we copy them by adding the rest of the items in the subarray to the array
    while (i <= mid) {

    }
	//same reasoning for the last while loop applies to this loop, but for the right subarray
    while (j <= high) {

    }
}

void sorts::mergesort(int data[], int low, int high) {
    //base case for recursive method calls: think about what should the recursive call be? What if we don't have enough items to actually sort through?
    
	if( /* insert base case condition*/) {
		return;
	}
    //look for the middle index to partition the array into 2 equal subarrays. We set a variable to determine the middle of the list

    //divide portion

    //call the merge sort method recursively on the left subarray (use that middle variable you just wrote above as a parameter)

	//call the merge sort method recursively on the right subarray (use that middle variable you just wrote above as a parameter)

	//conquer (where we call the helper function
}

void sorts::mergesort(int data[], int n) {
    mergesort(data, 0, n-1);
}

void sorts::swap(int& x, int& y){
  // DO NOT EDIT
  int temp = x;
  x = y;
  y = temp;
}

int sorts::partition(int data[], int low, int high) {
  //we could generate a random item for the pivot, but we're using a middle item instead
  int pivdex = (low+high)/2;
  //make the pivot be the last item in the array
  swap(data[pivdex], data[high]);

  //write code that decides what are the items that will be on the left side of the pivot or the right side of the pivot
  int i = low;
  //we need to write something that goes through the whole list, checks if the data being checked is less than the data within the pivot, ans swap accordingly

  //i tracks threshold item -> separates items that are smaller/greater than the pivot
  swap(data[i], data[high]);
  //return index of pivot
  return i;
}

void sorts::quicksort(int data[], int low, int high) {
  //base case, takes care of the same case we hinted on in mergesort
  if ( /* insert base case condition*/){
    return;
  }
  //find a pivot item, run the partition on the array according to what the pivot is
  //like merge sort, we make a variable to keep track of this

   //call this sort method recursively on left array (left of pivdex)

   //call this sort method recursively on right array (right of pivdex)
}

void sorts::quicksort(int data[], int n){
  quicksort(data, 0, n - 1);
}
