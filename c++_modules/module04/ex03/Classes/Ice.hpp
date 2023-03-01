#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : AMateria{
    private :
        std::string type;
    
    public :
        Ice();
        ~Ice();
        Ice(const Ice& copy);
        Ice& operator=(const Ice& copy);

        AMateria* clone();
        void use(ICharacter& target);
};

#endif