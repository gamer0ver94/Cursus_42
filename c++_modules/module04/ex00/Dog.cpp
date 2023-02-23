#include "Dog.hpp"

//_______________Default Constructor_____________
Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog Default Constructor" << std::endl;
}

//_______________Destructor____________________
Dog::~Dog(){
	std::cout << "Dog Destructor" << std::endl;
}

//______________Copy Constructor__________
Dog::Dog(const Animal& copy){
	this->type = copy.type;
	std::cout << "Copy Constructor" << std::endl;
}

//______________Assignment___________________
Dog& Dog::operator=(const Animal& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	return *this;
}

//_____________Make Sound Member Function_______
void Dog::makeSound(){
	std::cout << "Woof Woof" << std::endl;
}