#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pointers.h"
#include <iostream>

TEST_CASE("bookends") {
    SUBCASE("simple test, 3 elements") {
        const std::string tester[3]{"she", "sells", "seashells"};
        std::string output[2];
        Pointers::bookends(tester, 3, output); 
        //output should now look like: {"she","seashells"}
        REQUIRE(output[0] == "she");
        REQUIRE(output[1] == "seashells");
    }

    //add your own

}

TEST_CASE("switcharoo") {
    SUBCASE("simple test, replace idx 1") {
        std::string tester[5]{"mary", "had", "a", "little", "lamb"};
        std::string *ptr = { tester };
        Pointers::switcharoo(ptr,1,"bought"); 
        //tester now looks like: {“mary", "bought", "a", "little", "lamb"}
        REQUIRE(tester[0] == "mary");
        REQUIRE(tester[1] == "bought");
        REQUIRE(tester[2] == "a");
        REQUIRE(tester[3] == "little");
        REQUIRE(tester[4] == "lamb");
    }

    SUBCASE("simple test REPEAT not using explicit ptr, replace idx 1") {
        std::string tester[5]{"mary", "had", "a", "little", "lamb"};
        Pointers::switcharoo(tester,1,"bought"); 
        //tester now looks like: {“mary", "bought", "a", "little", "lamb"}
        REQUIRE(tester[0] == "mary");
        REQUIRE(tester[1] == "bought");
        REQUIRE(tester[2] == "a");
        REQUIRE(tester[3] == "little");
        REQUIRE(tester[4] == "lamb");
    }

    SUBCASE("simple test REPEAT using new, replace idx 1") {
        std::string *tester = new std::string[5];
        tester[0] = "mary";
        tester[1] =  "had";
        tester[2] = "a";
        tester[3] = "little";
        tester[4] = "lamb";
        Pointers::switcharoo(tester,1,"bought"); 
        //tester now looks like: {“mary", "bought", "a", "little", "lamb"}
        REQUIRE(tester[0] == "mary");
        REQUIRE(tester[1] == "bought");
        REQUIRE(tester[2] == "a");
        REQUIRE(tester[3] == "little");
        REQUIRE(tester[4] == "lamb");
    }

    //add your own

}