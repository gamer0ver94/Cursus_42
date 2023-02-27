#pragma once
#include <iostream>

class WrongAnimal{
	protected :
		std::string type;
	public :
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);

		virtual void makeSound()const;
		std::string getType()const;
};
