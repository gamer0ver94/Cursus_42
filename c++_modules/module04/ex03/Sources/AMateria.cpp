#include "../Classes/AMateria.hpp"

AMateria::AMateria(){

}

AMateria::AMateria(std::string const &type){
	this->type = type;
}

AMateria::~AMateria(){

}
AMateria::AMateria(const AMateria& copy){
	if (this != &copy){
		this->type = copy.type;
	}
}

AMateria& AMateria::operator=(const AMateria& copy){
	(void)copy;
	return *this;
}

std::string const& AMateria::getType()const{
	return this->type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}

AMateria* AMateria::clone() const{
	AMateria *c = 0;

	return c;
}