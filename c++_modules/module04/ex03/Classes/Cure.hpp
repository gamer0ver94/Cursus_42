#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : AMateria{
    public :
        Cure();
        ~Cure();
        Cure(const Cure& copy);
        Cure& operator=(const Cure& copy);

        AMateria* clone();
        void use(ICharacter& target);
};

#endif