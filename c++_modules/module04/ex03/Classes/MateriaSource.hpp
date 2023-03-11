#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    public :
		MateriaSource();
		MateriaSource(const IMateriaSource& copy);
		~MateriaSource();
		MateriaSource& operator=(const IMateriaSource& copy);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
	
	private :
		AMateria *(inventory[4]);
};

#endif
