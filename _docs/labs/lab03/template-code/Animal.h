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
    	virtual void Speak(std::ostream& os = std::cout) = 0;

    	/*The `ostream` is needed solely for testing, but you can also think of it as a 
    	generalization of printing. Instead of writing data to STDOUT using `std::cout`, 
    	you will instead write to the `ostream` passed in as an argument. */
};