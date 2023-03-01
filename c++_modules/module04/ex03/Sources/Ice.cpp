#include "../Classes/Ice.hpp"

//________Ice Constructor_________

Ice::Ice(){
    this->type = (std::string)"ice";
    std::cout << GREEN << "Ice Constructor" << WHITE << std::endl;
}

//________Ice Desctructor_________

Ice::~Ice(){
    std::cout << RED << "Ice Destructor" << WHITE << std::endl;
}

//________Copy Constructor_________

Ice::Ice(const Ice& copy){
    // this->type = copy.type;
    std::cout << CYAN << "Ice Copy Constructor" << WHITE << std::endl;
}

//_______Ice Copy Assignment___________
Ice& Ice::operator=(const Ice& copy){
    // if (this != &copy){
    //     this->type = copy.type;
    // }
    return *this;
}

AMateria* AMateria::clone() const{
	AMateria *c;
	c->type = this->type;
	return c;
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
 }