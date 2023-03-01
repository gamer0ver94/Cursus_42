#include "../Classes/Cure.hpp"

//________Cure Constructor_________

Cure::Cure(){
    this->type = (std::string)"cure";
    std::cout << GREEN << "Cure Constructor" << WHITE << std::endl;
}

//________Cure Desctructor_________

Cure::~Cure(){
    std::cout << RED << "Cure Destructor" << WHITE << std::endl;
}

//________Copy Constructor_________

Cure::Cure(const Cure& copy){
    this->type = copy.type;
    std::cout << CYAN << "Cure Copy Constructor" << WHITE << std::endl;
}

//_______Ice Copy Assignment___________
Cure& Cure::operator=(const Cure& copy){
    if (this != &copy){
        this->type = copy.type;
    }
    return *this;
}

AMateria* AMateria::clone() const{
	AMateria *c;
	c->type = this->type;
	return c;
}

 void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl;
 }