#include "Animal.hpp"

//_______________Default Constructor_____________
Animal::Animal(){
	this->type = "none";
	std::cout << "Animal Default Constructor" << std::endl;
}

//_______________Destructor____________________
Animal::~Animal(){
	std::cout << "Animal Destructor" << std::endl;
}

//______________Copy Constructor__________
Animal::Animal(const Animal& copy){
	this->type = copy.type;
	std::cout << "Copy Constructor" << std::endl;
}

//______________Assignment___________________
Animal& Animal::operator=(const Animal& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	return *this;
}

//_____________Make Sound Member Function_______
void Animal::makeSound(){
	
}

//_____________GETTER TYPE_________________

const std::string Animal::getType(){
	return (this->type);
}