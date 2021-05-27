// Dog.h
#include "Animal.h"

class Dog : public Animal{
    public:
        Dog(float initial_hunger) : Animal(initial_hunger){};
        void Speak(std::ostream& os = std::cout) { os << "Woof!" << std::endl; }
};