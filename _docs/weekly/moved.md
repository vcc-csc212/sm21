##### Object-Oriented Programming {#oop}

There are four primary principles of Object-Oriented Programming that are enumerated in any OOP introductory text, video, lecture, {insert medium of education here}. These are: Encapsulation, Abstraction, Inheritance, Polymorphism.

The core idea of OOP is that you design Classes which are then used to instantiate Objects that communicate with one another to solve a problem.

The following code is used to highlight the four principles mentioned:

```c++
// Animal.h
#pragma once
#include <iostream>

class Animal{
    private:
    	float hunger;

    public:
      Animal(float initial_hunger);
    	void Eat(float sustenance);
    	float GetHunger();
    	virtual void Speak() = 0;
};
```

> `#pragma once` is a non-standard pragma that is supported by the vast majority of modern compilers. If it appears in a header file, it indicates that it is only to be parsed once, even if it is (directly or indirectly) included multiple times in the same source file ([read more](https://en.cppreference.com/w/cpp/preprocessor/impl)).
<br><br>
The `virtual` keyword, when applied to a function, denotes a function that will be overriden by a child/derived class. When a class has a `virtual` function, it cannot be instantiated as it merely serves as a template for what its derived classes should look like (it's the equivalent of an abstract class in Java) ([read more](https://www.geeksforgeeks.org/virtual-function-cpp/)). 
<br><br>
When a class derives another class, we say it has an **is-a** relationship. This relationship allows the derived class to behave as itself and as its parent (the base class)-- this is called **polymorphism**. In the classes below, for example, we have a `Cat` class that we say **is-a** `Animal` and therefore it has all the same functionality as an `Animal`. While we can create an instance of a `Cat`, we cannot create an instance of an `Animal`.

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

##### Encapsulation

Also known as "data hiding", this is the principle that each Object keeps its state (content of memory) private (no one else can read it). Every field, method, and function in a class is given an encapsulation type of **Private, Protected, or Public**.

- Private
  - Can **only** be accessed by that object.
- Protected
  - Can **only** be access that that object **and** any object created from a subclass of that object.
- Public
  - Can be accessed by anything and everything in that program.

##### Abstraction

This is a tool in modeling higher-level mechanisms. In practice, this is used to code shared features that are implemented differently. 

In the above code, `Animal` is an Abstract class (the 'pure virtual' designation of `virtual void Speak() = 0;` makes this so.) If we tried to instantiate it, we would get an error. This makes sense model-wise, as there is no such thing as an "Animal". An animal is a higher-level classification for specific species. However, `Cat` and `Dog` are specific animals that we want to be able to create. Setting up our program like this allows us to only have to program changes we wish to make to multiple classes **once**. So if we wanted to start tracking age, placing it in Animal (then modifying the Cat/Dog constructors) is much more preferable than coding the same feature twice. While this seems overkill for this example, remember that this is **scalable**! I can now model any number of types of animals, that all have the same variables/functions, very quickly without copy/pasting a ton of times!

##### Inheritance

This principle allows us to "re-use" code by deriving multiple classes from a base class. In the example we just gave, `Animal` is the base class while `Dog` and `Cat` are the derived classes.

##### Polymorphism

This principle allows an object to be treated as a different type so long as it falls within the correct inheritance hierarchy. As an example, in the code we just reviewed we have an "is-a" relationship between Animal and Dog (A Dog is-a Animal.) This allows any Dog object to be stored as a Dog (`Dog myDog(50);`) or as an Animal pointer (`Animal* animal_ptr = new Dog(50);`).

#### Part 7.  Debugging {#debugging}

The hardest part of programming is figuring out where you went wrong. There are a few techniques we can use to narrow in on our mistakes:

1. Rubber-duck debugging
   - Often we just need to methodically work through the code. Unfortunately, we tend to make assumptions while reviewing code that we wrote. In an effort to prevent glossing over key portions, the goal of this type of debugging is to explain the code to someone as if they had never seen it before. Since it can be difficult to find someone to speak to every time you get stuck (hint: a lot) it is helpful to substitute in a rubber duck. Yes, the generic kind you find in/around bath tubs. Here is a bit more reading on the subject (I recommend giving this a quick read!) https://www.thoughtfulcode.com/rubber-duck-debugging-psychology/
2. Print Statements
   - Sometimes we just need to output everything our program is doing to track down the issue. This is *very* primitive, and does not scale well. But in an isolated environment is a quick and dirty way to discover where a calculation is going wrong. Bonus tip: Read input from the keyboard to "pause" your program and step through it slowly!
3. Use a real debugger
   - This is the proper way to perform technique #2. Set breakpoints accordingly, compile your code, run it through a debugger, and use the tools given to you to explore the values in all of the variables, check scope, trace the program control, etc. This process will differ based on the IDE you are using, lookup tutorials and reach out to staff for help.

------------------------

FOR POINTERS: 

- Read [Stack and Heap Memory](https://courses.engr.illinois.edu/cs225/fa2020/resources/stack-heap/)
- Watch [Stack Versus Heap](https://www.youtube.com/watch?v=IX3fDYz0WyM) (3 min)

#### Pre-Reading for Essential Math Overview, Thursday 1/28 {#thurs}

##### Essential Questions
Before attending class, please complete the material below and use the following questions to guide your note-taking:  
<br>
✔️ What are the rules and properties of **exponents**?  
✔️ What are the rules and properties of **logarithms**?  
✔️ What does **logarithmic** growth look like?  
✔️ What does **exponential** growth look like?  
✔️ When are **permutations** useful and how are they calculated?  
✔️ When are **combinations** useful and how are they calculated?  
✔️ When are **summations** useful and how are they calculated?  
✔️ When are **factorials** useful and how are they calculated?

##### Read/Watch/Review
Before attending class, please complete the material below. If your math is rough around the edges, I recommend checking out the [Math Prep Work](/sm21/prep#math) posted over break **before** completing the material below.
- Read [Rules of Exponents](https://www.chilimath.com/lessons/intermediate-algebra/rules-of-exponents/)
	- Alternatively, for a one-stop shop of Exponents and Logarithms, read [Exponentials: Discrete, Real, and Imaginary](https://sites.google.com/site/butwhymath/algebra/eponentials-discrete-real-and-imaginary)
- Read [Logarithms Explained](https://www.chilimath.com/lessons/advanced-algebra/logarithms-explained/)
- Read [Rules or Laws of Logarithms](https://www.chilimath.com/lessons/advanced-algebra/logarithm-rules/)
- Read/Watch [Permutations and Combinations](https://www.mathplanet.com/education/algebra-2/discrete-mathematics-and-probability/permutations-and-combinations)
- Read [Using Summation Notation](https://courses.lumenlearning.com/ivytech-collegealgebra/chapter/using-summation-notation/)
- Read [Summation Notation](https://tutorial.math.lamar.edu/Classes/CalcI/SummationNotation.aspx)(pay close attention to the **formulas**)
- Read/Watch [Simplifying Factorials: The Easy Way](https://medium.com/i-math/simplifying-factorials-the-easy-way-61c221c21b57)

##### In Class
In today's class we'll be doing going over some of the properties you learned about in the readings, relating them to our next topic of *analysis of algorithms*, and practicing getting comfortable with all the math symbols and jargon we'll be seeing the rest of the semester.