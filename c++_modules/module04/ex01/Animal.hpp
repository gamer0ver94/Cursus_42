#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

class Animal{
	protected :
		std::string type;
	public :
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);

		virtual void makeSound()const;
		std::string getType()const;
};
#endif