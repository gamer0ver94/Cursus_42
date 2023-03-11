#include "Cat.hpp"

//_______________Default Constructor_____________
Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << GREEN << "Cat Default Constructor" << WHITE << std::endl;
}

//_______________Destructor____________________
Cat::~Cat(){
	std::cout << RED << "Cat Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
Cat::Cat(const Cat& copy) : Animal(){
	this->type = copy.type;
	std::cout << CYAN << "Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
Cat& Cat::operator=(const Cat& copy){
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << BLUE << "CAT Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void Cat::makeSound()const{
	std::cout << YELLOW << "Miaw Miaw" << WHITE << std::endl;
}