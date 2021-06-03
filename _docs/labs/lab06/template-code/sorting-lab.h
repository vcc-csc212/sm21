#ifndef __SORTS__
#define __SORTS__

#include <ostream>
#include <algorithm>
#include <string> 

class sorts {
	public:
		sorts();
    	~sorts();
		void selectionSort(int * unsortedArr, int arrSize);
		void insertionSort(int * unsortedArr, int arrSize);
		void print(int data[], int n, std::ostream& os = std::cout);
};

#endif