#ifndef __SORTS__
#define __SORTS__

#include <ostream>
#include <algorithm>
#include <string> 

class sorts {
	private:
		static void merge(int data[], int temp[], int low, int mid, int high);
		static void mergesort(int data[], int low, int high);
		static void swap(int& x, int& y);
		static int partition(int data[], int low, int high);
		static void quicksort(int data[], int low, int high);

	public:
		static void print(int data[], int n, std::ostream& os = std::cout);
		static void mergesort(int data[], int n);
		static void quicksort(int data[], int n);

		// Curious about the static keyword? Read about it: https://www.geeksforgeeks.org/static-keyword-cpp/

		friend class private_tester;
};

class private_tester { 
// this class is used to test the private functions of the sorts class. allows us to keep private functions private while still allowing us to test usng doctest
	public:
		static void test_merge(int data[], int temp[], int low, int mid, int high) {
			sorts::merge(data, temp, low, mid, high);
		}
		static void test_mergesort(int data[], int low, int high) {
			sorts::mergesort(data, low, high);
		}
		static void test_swap(int& x, int& y) {
			sorts::swap(x, y);
		}
		static int test_partition(int data[], int low, int high) {
			return sorts::partition(data, low, high);
		}
		static void test_quicksort(int data[], int low, int high) {
			sorts::quicksort(data, low, high);
		}
};

#endif