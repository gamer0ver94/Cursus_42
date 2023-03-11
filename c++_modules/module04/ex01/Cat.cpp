#include "Cat.hpp"

//_______________Default Constructor_____________
Cat::Cat() : Animal(){
	std::cout << GREEN << "Cat Default Constructor" << WHITE << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

//_______________Destructor____________________
Cat::~Cat(){
	delete this->brain;
	std::cout << RED << "Cat Destructor" << WHITE << std::endl;
}

//______________Copy Constructor__________
Cat::Cat(const Cat& copy) : Animal(){
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << CYAN << "Cat Copy Constructor" << WHITE << std::endl;
}

//______________Assignment___________________
Cat& Cat::operator=(const Cat& copy){
	if (this != &copy){
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	std::cout << BLUE << "CAT Assigment Operator" << WHITE << std::endl;
	return *this;
}

//_____________Make Sound Member Function_______
void Cat::makeSound()const{
	std::cout << YELLOW << "Miaw Miaw" << WHITE << std::endl;
}

Brain* Cat::getBrain(){
	return(brain);
}

