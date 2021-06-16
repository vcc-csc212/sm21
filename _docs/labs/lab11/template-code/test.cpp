#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "node.h"
#include "linked_list.h"
#include <iostream>

// Uncomment the appropriate tests below as you implement each portion of the lab.

TEST_CASE("node") {
    SUBCASE("constructor setup-- shouldn't crash") {
        Node a_node;
        Node b_node('b');
        Node c_node('c', &a_node);
    }
    
    // add your own
}

TEST_CASE("linked list constructor") {
    SUBCASE("constructor setup-- shouldn't crash") {
        LinkedList my_list;
    }

    SUBCASE("size setup correct") {
        LinkedList my_list;
        REQUIRE(my_list.size() == 0);
    }

    SUBCASE("head setup correct") {
        LinkedList my_list;
        REQUIRE(my_list.to_string() == "");
    }
    
    // add your own
}

TEST_CASE("push_front") {
    SUBCASE("push 1 item") {
        LinkedList my_list;
        my_list.push_front('a');
        REQUIRE(my_list.to_string() == "a ");
        REQUIRE(my_list.size() == 1);
    }
    
    // add your own
}

TEST_CASE("push_back") {
    SUBCASE("push 1 item") {
        LinkedList my_list;
        my_list.push_back('a');
        REQUIRE(my_list.to_string() == "a ");
        REQUIRE(my_list.size() == 1);
    }
    
    // add your own
}

TEST_CASE("insert") {
    SUBCASE("push front 2 items, insert in middle") {
        LinkedList my_list;
        my_list.push_front('c');
        my_list.push_front('a');
        my_list.insert('b', 1u); // the u makes it so 1 is unsigned.
        REQUIRE(my_list.to_string() == "a b c ");
        REQUIRE(my_list.size() == 3);
    }
    
    // add your own
}

TEST_CASE("delete") {
    SUBCASE("push front 1 item, delete") {
        LinkedList my_list;
        my_list.push_front('c');
        my_list.del('c');
        REQUIRE(my_list.to_string() == "");
        REQUIRE(my_list.size() == 0);
    }
    
    // add your own
}

TEST_CASE("contains") {
    SUBCASE("push front 1 item, search exists") {
        LinkedList my_list;
        my_list.push_front('c');
        REQUIRE(my_list.contains('c') == true);
    }

    SUBCASE("push front 1 item, search does not exist") {
        LinkedList my_list;
        my_list.push_front('c');
        REQUIRE(my_list.contains('a') == false);
    }
    
    // add your own
}

TEST_CASE("mixing it up") {    
    // add your own
}