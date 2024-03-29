#include "Dog.hpp"

//_______________Default Constructor_____________
Dog::Dog() : Animal(){
	this->type = "Dog";
	std::cout << GREEN << "Dog Default Constructor" << WHITE << std::endl;
}

//_______________Destructor____________________
Dog::~Dog(){
	std::cout << RED << "Dog Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
Dog::Dog(const Dog& copy) : Animal(){
	this->type = copy.type;
	std::cout << CYAN << "Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
Dog& Dog::operator=(const Dog& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << BLUE << "DOG Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void Dog::makeSound()const{
	std::cout << YELLOW << "Woof Woof" << WHITE << std::endl;
}