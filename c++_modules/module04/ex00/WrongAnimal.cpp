#include "WrongAnimal.hpp"

//_______________Default Constructor_____________
WrongAnimal::WrongAnimal(){
	this->type = "none";
	std::cout << GREEN << "Animal Default Constructor" << WHITE << std::endl;
}

//_______________Destructor____________________
WrongAnimal::~WrongAnimal(){
	std::cout << RED << "Animal Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
WrongAnimal::WrongAnimal(const WrongAnimal& copy){
	this->type = copy.type;
	std::cout << CYAN << "Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << BLUE << "WRONG ANIMAL Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void WrongAnimal::makeSound()const{
	std::cout << "Wrong Animal sound" << std::endl;
}

//_____________GETTER TYPE_________________

std::string WrongAnimal::getType()const{
	return (this->type);
}