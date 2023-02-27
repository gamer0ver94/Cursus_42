#include "WrongCat.hpp"

//_______________Default Constructor_____________
WrongCat::WrongCat(){
	this->type = "Cat";
	std::cout << "Cat Default Constructor" << std::endl;
}

//_______________Destructor____________________
WrongCat::~WrongCat(){
	std::cout << "Cat Destructor" << std::endl;
}

//______________Copy Constructor__________
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(){
	this->type = copy.type;
	std::cout << "Copy Constructor" << std::endl;
}

//______________Assignment___________________
WrongCat& WrongCat::operator=(const WrongCat& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	return *this;
}

//_____________Make Sound Member Function_______
void WrongCat::makeSound()const{
	std::cout << "Wrong Animal" << std::endl;
}