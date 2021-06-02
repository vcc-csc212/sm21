#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DynamicArray.h"
#include <iostream>

TEST_CASE("Default Con/Destructor") {
    SUBCASE("Constructor Compiles"){
        DynamicArray da_def;
    }

    SUBCASE("Sets values correctly"){
        DynamicArray da_def;
        REQUIRE(da_def.getLength() == 0);
        REQUIRE(da_def.getCapacity() == 0);
        REQUIRE(da_def.getScalingFactor() == 2);
    }

    SUBCASE("Destructor Compiles"){
        DynamicArray da_def;
        da_def.~DynamicArray();
    }
}

//TO DO: uncomment the tests below when you're at the respective step

// TEST_CASE("Overloaded Constructors") {
//     SUBCASE("Compiles"){
//         DynamicArray da_cap(2, 5);
//         DynamicArray da_fill(2, 5, 0);
        
//         //add your own

//     }

//     SUBCASE("Sets values correctly"){
//         DynamicArray da_cap(2, 5);
//         REQUIRE(da_cap.getLength() == 0);
//         REQUIRE(da_cap.getCapacity() == 5);
//         REQUIRE(da_cap.getScalingFactor() == 2);

//         DynamicArray da_fill(2, 5, 0);
//         REQUIRE(da_fill.getLength() == 5);
//         REQUIRE(da_fill.getCapacity() == 5);
//         REQUIRE(da_fill.getScalingFactor() == 2);
//         REQUIRE(da_fill.toString() == "{0 0 0 0 0}");

//         //add your own

//     }
// }

// TEST_CASE("Insertion") {
//     SUBCASE("Append"){
//         DynamicArray da_def;
//         da_def.append(5);
//         REQUIRE(da_def.toString() == "{5}");
//         REQUIRE(da_def.getLength() == 1);
//         REQUIRE(da_def.getCapacity() == 1);
//         da_def.append(50);
//         REQUIRE(da_def.toString() == "{5 50}");
//         REQUIRE(da_def.getLength() == 2);
//         REQUIRE(da_def.getCapacity() == 2);
//         da_def.append(500);
//         REQUIRE(da_def.toString() == "{5 50 500}");
//         REQUIRE(da_def.getLength() == 3);
//         REQUIRE(da_def.getCapacity() == 4);
        
//         DynamicArray da_cap(3, 1);
//         da_cap.append(5);
//         REQUIRE(da_cap.toString() == "{5}");
//         REQUIRE(da_cap.getLength() == 1);
//         REQUIRE(da_cap.getCapacity() == 3);
//         da_cap.append(50);
//         REQUIRE(da_cap.toString() == "{5 50}");
//         REQUIRE(da_cap.getLength() == 2);
//         REQUIRE(da_cap.getCapacity() == 3);
//         da_cap.append(500);
//         REQUIRE(da_cap.toString() == "{5 50 500}");
//         REQUIRE(da_cap.getLength() == 3);
//         REQUIRE(da_cap.getCapacity() == 3);
//         da_cap.append(5000);
//         REQUIRE(da_cap.toString() == "{5 50 500 5000}");
//         REQUIRE(da_cap.getLength() == 3);
//         REQUIRE(da_cap.getCapacity() == 9);

//         DynamicArray da_fill(5, 5, 0);
//         da_fill.append(5);
//         REQUIRE(da_fill.toString() == "{0 0 0 0 0 5}");
//         REQUIRE(da_fill.getLength() == 6);
//         REQUIRE(da_fill.getCapacity() == 25);
//         da_fill.append(50);
//         REQUIRE(da_fill.toString() == "{0 0 0 0 0 5 50}");
//         REQUIRE(da_fill.getLength() == 7);
//         REQUIRE(da_fill.getCapacity() == 25);

//         //add your own

//     }

//     SUBCASE("Prepend"){
//         //add your own
//     }
// }

// TEST_CASE("Finding") {
//     SUBCASE("Find first of"){
//         DynamicArray da_def;
//         da_def.append(5);
//         da_def.append(50);
//         da_def.append(5);

//         unsigned int* index;
//         bool found;

//         found = da_def.findFirstOf(5, index);
//         REQUIRE(found == true);
//         REQUIRE(*index == 0);

//         found = da_def.findFirstOf(50, index);
//         REQUIRE(found == true);
//         REQUIRE(*index == 1);

//         found = da_def.findFirstOf(500, index);
//         REQUIRE(found == false);
//         REQUIRE(*index == -1);

//         //add your own
//     }

//     SUBCASE("Find last of"){
//         DynamicArray da_def;
//         da_def.append(5);
//         da_def.append(50);
//         da_def.append(5);

//         unsigned int* index;
//         bool found;

//         found = da_def.findLastOf(5, index);
//         REQUIRE(found == true);
//         REQUIRE(*index == 2);

//         found = da_def.findLastOf(50, index);
//         REQUIRE(found == true);
//         REQUIRE(*index == 1);

//         found = da_def.findLastOf(500, index);
//         REQUIRE(found == false);
//         REQUIRE(*index == -1);

//         //add your own
//     }

// }

// TEST_CASE("Deletion") {
//     SUBCASE("Remove First"){
//         DynamicArray da_def;
//         da_def.append(5);
//         da_def.append(50);
//         da_def.append(500);

//         da_def.removeFirst();
//         REQUIRE(da_def.toString() == "{50 500}");
//         REQUIRE(da_def.getLength() == 2);
//         REQUIRE(da_def.getCapacity() == 4);
        
//         da_def.removeFirst();
//         REQUIRE(da_def.toString() == "{500}");
//         REQUIRE(da_def.getLength() == 1);
//         REQUIRE(da_def.getCapacity() == 2);

//         da_def.removeFirst();
//         REQUIRE(da_def.toString() == "{}");
//         REQUIRE(da_def.getLength() == 0);
//         REQUIRE(da_def.getCapacity() == 1);

//         //add your own

//     }

//     SUBCASE("Remove Last"){
//         DynamicArray da_def;
//         da_def.append(5);
//         da_def.append(50);
//         da_def.append(500);

//         da_def.removeFirst();
//         REQUIRE(da_def.toString() == "{5 50}");
//         REQUIRE(da_def.getLength() == 2);
//         REQUIRE(da_def.getCapacity() == 4);
        
//         da_def.removeFirst();
//         REQUIRE(da_def.toString() == "{5}");
//         REQUIRE(da_def.getLength() == 1);
//         REQUIRE(da_def.getCapacity() == 2);

//         da_def.removeFirst();
//         REQUIRE(da_def.toString() == "{}");
//         REQUIRE(da_def.getLength() == 0);
//         REQUIRE(da_def.getCapacity() == 1);

//         //add your own
//     }

//     SUBCASE("Clear"){
//         DynamicArray da_def;
//         da_def.append(5);
//         da_def.append(50);
//         da_def.append(500);

//         da_def.clear();
//         REQUIRE(da_def.toString() == "{}");
//         REQUIRE(da_def.getLength() == 0);
//         REQUIRE(da_def.getCapacity() == 0);

//         //add your own
//     }
// }
