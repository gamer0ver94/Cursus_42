#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include "AMateria.hpp"

class IMateriaSource{
    public :
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif