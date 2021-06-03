#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sorting-lab.h"
#include <iostream>

TEST_CASE("Constructor") {
    sorts t;
}

TEST_CASE("Destructor") {
    sorts *t = new sorts;
    delete t;
}

TEST_CASE("selection sort") {
    SUBCASE("1 elem"){
        sorts t;
        const int size = 1;
        int arr[size] = {1};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted odd"){
        sorts t;
        const int size = 3;
        int arr[size] = {1,2,3};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    SUBCASE("sorted even"){
        sorts t;
        const int size = 4;
        int arr[size] = {1,2,3,4};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 4 ");
    }

    SUBCASE("unsorted even"){
        sorts t;
        const int size = 4;
        int arr[size] = {4,2,3,1};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 4 ");
    }

    SUBCASE("unsorted odd"){
        sorts t;
        const int size = 3;
        int arr[size] = {3,1,2};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    SUBCASE("reverse odd"){
        sorts t;
        const int size = 3;
        int arr[size] = {3,2,1};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    SUBCASE("reverse even"){
        sorts t;
        const int size = 4;
        int arr[size] = {4,3,2,1};
        t.selectionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 4 ");
    }
}

TEST_CASE("insertion sort") {
    SUBCASE("1 elem"){
        sorts t;
        const int size = 1;
        int arr[size] = {1};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 ");
    }

    SUBCASE("sorted odd"){
        sorts t;
        const int size = 3;
        int arr[size] = {1,2,3};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    SUBCASE("sorted even"){
        sorts t;
        const int size = 4;
        int arr[size] = {1,2,3,4};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 4 ");
    }

    SUBCASE("unsorted even"){
        sorts t;
        const int size = 4;
        int arr[size] = {4,2,3,1};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 4 ");
    }

    SUBCASE("unsorted odd"){
        sorts t;
        const int size = 3;
        int arr[size] = {3,1,2};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    SUBCASE("reverse odd"){
        sorts t;
        const int size = 3;
        int arr[size] = {3,2,1};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 ");
    }

    SUBCASE("reverse even"){
        sorts t;
        const int size = 4;
        int arr[size] = {4,3,2,1};
        t.insertionSort(arr, size);
        std::ostringstream oss;
        t.print(arr, size, oss);
        REQUIRE(oss.str() == "1 2 3 4 ");
    }
}