#include "Animal.hpp"

//_______________Default Constructor_____________
Animal::Animal() : type("None"){
	std::cout << GREEN << "Animal Default Constructor" << WHITE << std::endl;
}

//_______________Destructor____________________
Animal::~Animal(){
	std::cout << RED << "Animal Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
Animal::Animal(const Animal& copy) : type(copy.type){
	this->type = copy.type;
	std::cout << CYAN << "Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
Animal& Animal::operator=(const Animal& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << BLUE << "ANIMAL Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void Animal::makeSound()const{
	std::cout << YELLOW << "..." << WHITE << std::endl;
}

//_____________GETTER TYPE_________________

std::string Animal::getType()const{
	return (this->type);
}