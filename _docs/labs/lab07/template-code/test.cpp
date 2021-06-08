#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "binary_search.h"
#include <iostream>

TEST_CASE("Item present") {
    SUBCASE("1 elem") {
        int arr[1] = {5};
        REQUIRE(BinarySearch::binary_search(5, arr, 1) == 0);
    }

    SUBCASE("2 elem, first") {
        int arr[2] = {5,10};
        REQUIRE(BinarySearch::binary_search(5, arr, 2) == 0);
    }

    SUBCASE("2 elem, last") {
        int arr[2] = {5,10};
        REQUIRE(BinarySearch::binary_search(10, arr, 2) == 1);
    }

    SUBCASE("3 elem, first") {
        int arr[3] = {5,10,3};
        REQUIRE(BinarySearch::binary_search(5, arr, 3) == 0);
    }

    SUBCASE("3 elem, mid") {
        int arr[3] = {5,10,3};
        REQUIRE(BinarySearch::binary_search(10, arr, 3) == 1);
    }

    SUBCASE("3 elem, last") {
        int arr[3] = {5,10,3};
        REQUIRE(BinarySearch::binary_search(3, arr, 3) == 2);
    }

    //add your own

}

TEST_CASE("Item not present") {
    SUBCASE("1 elem") {
        int arr[1] = {5};
        REQUIRE(BinarySearch::binary_search(52, arr, 1) == -1);
    }

    SUBCASE("2 elem, first") {
        int arr[2] = {5,10};
        REQUIRE(BinarySearch::binary_search(52, arr, 2) == -1);
    }

    SUBCASE("2 elem, last") {
        int arr[2] = {5,10};
        REQUIRE(BinarySearch::binary_search(102, arr, 2) == -1);
    }

    SUBCASE("3 elem, first") {
        int arr[3] = {5,10,3};
        REQUIRE(BinarySearch::binary_search(52, arr, 3) == -1);
    }

    SUBCASE("3 elem, mid") {
        int arr[3] = {5,10,3};
        REQUIRE(BinarySearch::binary_search(102, arr, 3) == -1);
    }

    SUBCASE("3 elem, last") {
        int arr[3] = {5,10,3};
        REQUIRE(BinarySearch::binary_search(32, arr, 3) == -1);
    }

    //add your own

}