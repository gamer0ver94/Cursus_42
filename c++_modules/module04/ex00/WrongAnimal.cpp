#include "WrongAnimal.hpp"

//_______________Default Constructor_____________
WrongAnimal::WrongAnimal(){
	this->type = "none";
	std::cout << "Animal Default Constructor" << std::endl;
}

//_______________Destructor____________________
WrongAnimal::~WrongAnimal(){
	std::cout << "Animal Destructor" << std::endl;
}

//______________Copy Constructor__________
WrongAnimal::WrongAnimal(const WrongAnimal& copy){
	this->type = copy.type;
	std::cout << "Copy Constructor" << std::endl;
}

//______________Assignment___________________
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	return *this;
}

//_____________Make Sound Member Function_______
void WrongAnimal::makeSound()const{
	std::cout << "..." << std::endl;
}

//_____________GETTER TYPE_________________

std::string WrongAnimal::getType()const{
	return (this->type);
}