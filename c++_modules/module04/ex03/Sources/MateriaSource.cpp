#include "../Classes/IMateriaSource.hpp"
#include "../Classes/MateriaSource.hpp"
#include "../Classes/Ice.hpp"
#include "../Classes/Cure.hpp"
MateriaSource::MateriaSource(){
    std::cout << "Created a MateriaSource" << std::endl;
}

MateriaSource::~MateriaSource(){
    (void)inventory[1];
}
MateriaSource::MateriaSource(const IMateriaSource& copy){
(void)copy;
}
MateriaSource& MateriaSource::operator=(const IMateriaSource& copy){
    (void)copy;
    return *this;
}

void MateriaSource::learnMateria(AMateria*) {
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    if (type == "ice") {
        return new Ice();
    } else if (type == "cure") {
        return new Cure();
    }
    return NULL;
}
