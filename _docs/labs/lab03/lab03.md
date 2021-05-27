---
title: OOP Crash Course
asg: Lab 3
permalink: /lab03/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of object oriented programming (OOP). Understanding OOP is crucial not only as a computer scientist, but in particular to understanding the data structures we'll be studying throughout the semester.

---

#### Background Info {#bgi}

There are four primary principles of Object-Oriented Programming that are enumerated in any OOP introductory text, video, lecture, etc. These are: Encapsulation, Abstraction, Inheritance, Polymorphism.

The core idea of OOP is that you design Classes which are then used to instantiate Objects that communicate with one another to solve a problem.

##### Encapsulation

Also known as "data hiding", this is the principle that **each Object keeps its state (content of memory) private** (no one else can read it). Every field, method, and function in a class is given an encapsulation type of **Private, Protected, or Public**.

- Private
  - Can **only** be accessed by **that** object.
- Protected
  - Can **only** be accessed that object **and** any object created from a **subclass** of that object.
- Public
  - Can be accessed by **anything** and everything in that program.

##### Abstraction

This is a tool in modeling higher-level mechanisms. In practice, this is used to **code shared features that are implemented differently**. 

##### Inheritance

This principle allows us to "re-use" code by deriving multiple classes from a base class. 

##### Polymorphism

This principle allows an object to be treated as a different type so long as it falls within the correct inheritance hierarchy. 

> The following code is used to highlight the four principles mentioned, look for the "**Concept in action**" notes to understand the relationship between the concept and its use and implementation in code.

```c++
// Animal.h
#pragma once //see below for what pragma once means
#include <iostream>

class Animal{
    private:
    	float hunger;

    public:
      Animal(float initial_hunger);
    	void Eat(float sustenance);
    	float GetHunger();
    	virtual void Speak() = 0; //see below for what the virtual keyboard means
};
```

**Concept in action (Encapsulation):** The use of the `private` and `public` allows us to hide certain data aspects of animal, in this case `hunger`. Hiding the member variable allows us to make sure no one can accidentally access and modify it. However, since reading the value of `hunger` might be helpful, so we make a public getter function to return the value.

> 
- `#pragma once`: If it appears in a header file, it indicates that it is **only to be parsed once**, even if it is (directly or indirectly) included multiple times in the same source file ([read more](https://en.cppreference.com/w/cpp/preprocessor/impl)).
<br><br>
- `virtual`: A keyword that when applied to a function, denotes a function that **will be overriden by a child/derived class**. When a class has a `virtual` function, it cannot be instantiated as it merely serves as a template for what its derived classes should look like (it's the equivalent of an abstract class in Java) ([read more](https://www.geeksforgeeks.org/virtual-function-cpp/)). 
	- When a class derives another class, we say it has an **is-a** relationship. This relationship allows the derived class to behave as itself and as its parent (the base class)-- this is called **polymorphism**. 
		- In the classes below, for example, we have a `Cat` class that we say **is-a** `Animal` and therefore it has all the same functionality as an `Animal`. While we can create an instance of a `Cat`, we cannot create an instance of an `Animal`.

**Concept in action (Abstraction, part 1):** In the above code, `Animal` is an Abstract class (the 'pure virtual' designation of `virtual void Speak() = 0;` makes this so.) If we tried to instantiate it, we would get an error. This makes sense model-wise, as there is no such thing as an "Animal"-- an animal is a higher-level classification for specific species. 

```c++
// Animal.cpp
#include "Animal.h"

Animal::Animal(float initial_hunger){
    this->hunger = initial_hunger;
}

float Animal::GetHunger(){
    return this->hunger;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}


```

> While the dot operator (`.`) simply accesses a data member, using the arrow operator (`->`) access them via a pointer ([read more](https://www.tutorialspoint.com/cplusplus/cpp_member_operators.htm)).

```c++
// Cat.h
#include "Animal.h"

class Cat : public Animal{
    public:
        Cat(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Meow!" << std::endl; }
};
```

```c++
// Dog.h
#include "Animal.h"

class Dog : public Animal{
    public:
        Dog(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Woof!" << std::endl; }
};
```

**Concept in action (Abstraction, part 2):** Unlike `Animal` which is a higher-level classification for specific species, `Cat` and `Dog` are specific animals that we want to be able to create. Setting up our program like this allows us to only have to program changes we wish to make to multiple classes **once**. So if we wanted to start tracking age, placing it in Animal (then modifying the Cat/Dog constructors) is much more preferable than coding the same feature twice. While this seems overkill for this example, remember that this is **scalable**! I can now model any number of types of animals, that all have the same variables/functions, very quickly without copy/pasting a ton of times!

**Inheritance in action:** In this example, `Animal` is the base class while `Dog` and `Cat` are the derived classes.

```c++
#include "Cat.h"
#include "Dog.h"

int main(){
    Cat cat1(50);	// object constructed during compile-time
    Dog* dog1 = new Dog(40);	// object constructed during run-time. 'dog1' is a pointer.

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    cat1.Eat(10);
    dog1->Eat(40);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    cat1.Speak();
    dog1->Speak();
}
```

**Concept in action (Polymorphism):** In the code above we have an "is-a" relationship between Animal and Dog (a Dog is-a Animal). This allows any Dog object to be stored as a Dog (`Dog myDog(50);`) or as an Animal pointer (`Animal* animal_ptr = new Dog(50);`).

##### A quick note on makefiles

Recall from Lab 2 that a makefile is **a file containing the set of instructions required to compile and run your program**. The nice thing about a makefile is that if it is created correctly, all you need to do to compile your code is run the command `make`, no arguments needed. 

For more information about makefiles, read [Makefile Tutorial By Example](https://makefiletutorial.com). The TLDR version is: A Makefile consists of a set of rules. A rule generally looks like this:
```
targets: prerequisites
   command
   command
   command
```
The **targets** are file names, separated by spaces. Typically, there is only one per rule.
The **commands** are a series of steps typically used to make the target(s). These need to start with a tab character, not spaces.
The **prerequisites** are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called dependencies

The makefile we have given you is already completed and beyond compiling your code, it goes one step further and runs your program immediately after compiling and then removes the binary it created. 

> Make sure you understand how it works because you'll be asked to make your own makefile in the future!

---

#### Your Task {#task}

The instructions below will walk you through applying OOP concepts as well as testing them using your own automated tester!

1. Download the files below (it's easiest if you right click and then choose download or save)

    [Animal.h](/sm21/labs/lab03/template-code/Animal.h)
    : Contains the **declaration** of the abstract Animal class from the example above.

    [Animal.cpp](/sm21/labs/lab03/template-code/Animal.cpp)
    : Contains the **definition** of the abstract Animal class from the example above.

    [Dog.h](/sm21/labs/lab03/template-code/Dog.h)
    : Contains the **declaration** of the concrete Dog class from the example above. Dog is-a Animal (`class Dog : public Animal` makes it so).

    [Cat.h](/sm21/labs/lab03/template-code/Cat.h)
    : Contains the **declaration** of the concrete Cat class from the example above. Cat is-a Animal (`class Cat : public Animal` makes it so).

    [main.cpp](/sm21/labs/lab03/template-code/main.cpp)
    : Contains some preliminary code so you can see how Dog and Cat work.

    [test.cpp](/sm21/labs/lab03/template-code/test.cpp)
    : Contains some tests that should pass as soon as you download the code, without you having to change anything, as well as some tests that should pass after you have completed the tasks below. **You should add your own test cases to this file**.

    [doctest.h](/sm21/labs/lab03/template-code/doctest.h)
    : The library we'll be using for our own automated tester. There's a ton of code in here so don't worry too much about understanding everything it does-- just know the library is extremely powerful and we'll only be scratching the surface of everything it can do. **Do not edit this file**.

    [makefile](/sm21/labs/lab03/template-code/makefile)
    : File used to compile and run your program. Note that the makefile **does not run main.cpp** it just runs the test cases. **To run main.cpp**, use: `g++ Animal.cpp main.cpp -o prog && ./prog`

2. Once you have downloaded all the files, inspect them. Ask questions if you have them.
3. Run, compile, and test your program by running `make` in your terminal, while in the directory all these files are located in.
4. Add three more types of Animals, each in their own header file: Bird, Hamster, Snake. 
    - For the `Speak()` function, use the following, respectively: "Chirp!", "Squeak!", "Hiss!"
5. Create 1 object of each type, similar to how Cat and Dog are created (in main), and call their functions.
6. Add test cases to test.cpp, then run `make` again to ensure your code works as expected.
    - Remember that the makefile **does not run main.cpp** it just runs the test cases. **To run main.cpp**, use: `g++ Animal.cpp main.cpp -o prog && ./prog`
7. Animals have ages-- add an age attribute to `Animal`, add a getter for it (`GetAge()`), and overload your constructor to take in an age and set the internal member variable. **The default constructor should set the age to 0.**
8. Add test cases to test.cpp, then run `make` again to ensure your code works as expected.
9. Add command line arguments (CLAs) to facilitate the following: number_of_animals, {default constructor values for each animal to be created}. Remember that the makefile **does not run main.cpp**. **To run main.cpp**, use: `g++ Animal.cpp main.cpp -o prog && ./prog`.

    > For more info on CLAs, please refer back to [Lab 2](/sm21/lab02).

    - number_of_animals will control a loop that prompts the user for what type of animal they wish to be created (you should have 5 types: Cat, Dog, Bird, Hamster, Snake).
    - The values will be stored in `argv` and used when you create each Animal.

    For example, running:

    ```
    g++ Animal.cpp main.cpp -o prog && ./prog 4 30 40 50 60
    ```

    ...should prompt the user four times for an animal type (make sure to **print `Enter an animal: ` each time**). If the user enters:

    ```
    Dog
    Cat
    Bird
    Snake
    ```

    ...then your program should populate an array of Animals that looks like this:

    ```
    | Dog: hunger = 30 | Cat: hunger = 40 | Bird: hunger = 50 | Snake: hunger = 60 |
    ```

    > `Animal**` is how you will create the array to store the animals (i.e. `Animal** arr = new Animal*[4];` would create an array that stores 4 animal pointers). Use the `new` keyword to instantiate each animal during run-time! **What OOP concept is this an example of?**

10. Create a simple loop to output each animal speaking & its hunger value to show that #9 works properly. Ex:

    ```
    Woof!
    30
    Meow!
    40
    Chirp!
    50
    Hiss!
    60
    ```

11. **Comment out everything in main() except** for the code for task items 9 and 10.

---

#### Requirements {#reqs}
Your submission will be **tested and graded by an autograder**, for this reason it cannot be stressed enough that your program must **exactly** follow the assignment specifications:  

1. Bird, Snake, and Hamster are derived classes from Animal
2. Bird, Snake, and Hamster respectively speak "Chirp!", "Hiss!", "Squeak!"
3. All animals have an age attribute that can be set via an overloaded constructor and gotten via GetAge()
4. All animals get their age set to 0 via the default constructor.
5. Main program (in main.cpp) has been updated to take in CLAs as specified in task item 9.
6. Main program (in main.cpp) has been updated to only print out the results of task items 9 and 10.

---

#### Handing in {#submit}
> Please note that the assignment **currently doesn't have a submission option on Gradescope**. I will **let you know as soon as this is set up**! In the mean time, use your self-built automated tester to test task items 1-8 and manually check 9-11.

To submit your solution to Gradescope, select **all of the following files** and use the *drag and drop* option:
- Animal.h
- Animal.cpp
- Dog.h
- Cat.h
- Bird.h
- Snake.h
- Hamster.h
- main.cpp

---

#### Grade Breakdown {#grading}
You must successfully meet [requirement](#reqs) **1 through 6** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/) and [Michael Conti](https://web.uri.edu/cs/meet/michael-conti/), modified assignment version by Christian Esteves, used and modified (again) with permission.
