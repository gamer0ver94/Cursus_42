#include "WrongCat.hpp"

//_______________Default Constructor_____________
WrongCat::WrongCat(){
	this->type = "Cat";
	std::cout << GREEN << "WRONG Cat Default Constructor" << WHITE << std::endl;
}

//_______________Destructor____________________
WrongCat::~WrongCat(){
	std::cout << RED << "WRONG Cat Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(){
	this->type = copy.type;
	std::cout << GREEN << "WRONG Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
WrongCat& WrongCat::operator=(const WrongCat& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << BLUE << "WRONG CAT Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void WrongCat::makeSound()const{
	std::cout << "Miaw Miaw<>" << std::endl;
}