// Cat.h
#include "Animal.h"

class Cat : public Animal{
    public:
        Cat(float initial_hunger) : Animal(initial_hunger){};
        void Speak(std::ostream& os = std::cout) { os << "Meow!" << std::endl; }
};