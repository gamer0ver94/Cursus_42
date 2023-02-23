#include "Cat.hpp"

//_______________Default Constructor_____________
Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat Default Constructor" << std::endl;
}

//_______________Destructor____________________
Cat::~Cat(){
	std::cout << "Cat Destructor" << std::endl;
}

//______________Copy Constructor__________
Cat::Cat(const Animal& copy){
	this->type = copy.type;
	std::cout << "Copy Constructor" << std::endl;
}

//______________Assignment___________________
Cat& Cat::operator=(const Animal& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	return *this;
}

//_____________Make Sound Member Function_______
void Cat::makeSound(){
	std::cout << "Miaw Miaw" << std::endl;
}