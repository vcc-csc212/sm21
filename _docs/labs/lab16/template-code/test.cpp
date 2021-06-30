#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lab16.h"
#include <iostream>

TEST_CASE("merge sort public") {
    SUBCASE("1 elem"){
        const int size = 1;
        int arr[size] = {1};
        sorts::mergesort(arr, size);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted order, odd num of elems"){
        const int size = 3;
        int arr[size] = {1,2,3};
        sorts::mergesort(arr, size);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    //add your own
}

TEST_CASE("quick sort public") {
    SUBCASE("1 elem"){
        const int size = 1;
        int arr[size] = {1};
        sorts::quicksort(arr, size);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted order, odd num of elems"){
        const int size = 3;
        int arr[size] = {1,2,3};
        sorts::quicksort(arr, size);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    //add your own
}

TEST_CASE("merge sort private helper") {
    SUBCASE("1 elem"){
        const int size = 1;
        int arr[size] = {1};
        private_tester::test_mergesort(arr, 0, 0);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted order, odd num of elems"){
        const int size = 3;
        int arr[size] = {1,2,3};
        private_tester::test_mergesort(arr, 1, 2);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    //add your own, pay attention to how we are testing private functions!
}

TEST_CASE("quick sort private helper") {
    SUBCASE("1 elem"){
        const int size = 1;
        int arr[size] = {1};
        private_tester::test_quicksort(arr, 0, 0);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted order, odd num of elems"){
        const int size = 3;
        int arr[size] = {1,2,3};
        private_tester::test_quicksort(arr, 1, 2);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    //add your own, pay attention to how we are testing private functions!
}

TEST_CASE("merge") {
    SUBCASE("1 elem"){
        const int size = 1;
        int arr[size] = {1};
        int temp[size];
        private_tester::test_merge(arr, temp, 0, 0, 0);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted order, odd num of elems"){
        const int size = 3;
        int arr[size] = {1,2,3};
        int temp[size];
        private_tester::test_merge(arr, temp, 0, 1, 2);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    //add your own, pay attention to how we are testing private functions!
}

TEST_CASE("partition") {
    SUBCASE("1 elem"){
        const int size = 1;
        int arr[size] = {1};
        private_tester::test_partition(arr, 0, 0);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted order, odd num of elems"){
        const int size = 3;
        int arr[size] = {1,2,3};
        private_tester::test_partition(arr, 1, 2);
        std::ostringstream oss;
        sorts::print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    //add your own, pay attention to how we are testing private functions!
}