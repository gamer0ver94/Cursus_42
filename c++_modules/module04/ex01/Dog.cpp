#include "Dog.hpp"

//_______________Default Constructor_____________
Dog::Dog() : Animal(){
	std::cout << GREEN << "Dog Default Constructor" << WHITE << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

//_______________Destructor____________________
Dog::~Dog(){
	delete this->brain;
	std::cout << RED << "Dog Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
Dog::Dog(const Dog& copy) : Animal(){
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << CYAN << "Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
Dog& Dog::operator=(const Dog& copy){
	if (this != &copy){
		this->type = copy.type;
		this->brain = new Brain(*copy.brain);
	}
	std::cout << BLUE << "DOG Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void Dog::makeSound()const{
	std::cout << YELLOW << "Woof Woof" << WHITE << std::endl;
}