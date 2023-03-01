#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : AMateria{
    public :
        Ice();
        ~Ice();
        Ice(const Ice& copy);
        Ice& operator=(const Ice& copy);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif