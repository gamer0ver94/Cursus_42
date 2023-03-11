#include "WrongAnimal.hpp"

//_______________Default Constructor_____________
WrongAnimal::WrongAnimal() : type("None"){
	std::cout << GREEN << "Wrong Animal Default Constructor" << WHITE << std::endl;
}

//_______________Destructor____________________
WrongAnimal::~WrongAnimal(){
	std::cout << RED << "Wrong Animal Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type){
	std::cout << CYAN << "Wrong Animal Copy Constructor" << WHITE << std::endl;
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