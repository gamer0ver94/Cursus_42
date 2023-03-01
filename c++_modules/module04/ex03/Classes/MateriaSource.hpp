#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : IMateriaSource{
    public :
		MateriaSource();
		MateriaSource(const IMateriaSource& copy);
		MateriaSource& operator=(const IMateriaSource& copy);
		~MateriaSource() {}
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
