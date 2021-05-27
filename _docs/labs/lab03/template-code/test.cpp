#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
//TO DO: uncomment the one below when you're at the respective step
// #include "Bird.h"
// #include "Hamster.h"
// #include "Snake.h"
#include <iostream>

TEST_CASE("Default Constructors") {
    SUBCASE("Compiles"){
        Dog dog(40);
        Cat cat(50);
        //add your own
    }

    SUBCASE("Sets hunger correctly"){
        Dog dog(40);
        REQUIRE(dog.GetHunger() == 40);
        Cat cat(50);
        REQUIRE(cat.GetHunger() == 50);
        //add your own
    }
}

//TO DO: uncomment the one below when you're at the respective step
// TEST_CASE("Overloaded Constructors") {
//     SUBCASE("Compiles"){
    //     Dog dog(40, 3);
    //     Cat cat(50, 1);
    //     //add your own
    // }

    // SUBCASE("Sets hunger and age correctly"){
    //     Dog dog(10, 3);
    //     REQUIRE(dog.GetHunger() == 10);
    //     REQUIRE(dog.GetAge() == 3);
    //     Cat cat(23, 1);
    //     REQUIRE(cat.GetHunger() == 23);
    //     REQUIRE(cat.GetAge() == 1);
    //     //add your own
    // }

    //remember default constructor should now set age to 0. add tests to confirm!
// }

TEST_CASE("Speak tests") {
    SUBCASE("DOG") {
        std::ostringstream oss;
        Dog dog(50);
        dog.Speak(oss);
        REQUIRE(oss.str() == "Woof!\n");
    }
    //add your own
}

TEST_CASE("Plymorphism tests") {
    SUBCASE("Dog") {
        std::ostringstream oss;
        Animal *dog = new Dog(50);
        dog->Speak(oss);
        REQUIRE(oss.str() == "Woof!\n");
    }
    //add your own
}
