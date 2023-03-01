#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

class AMateria{
    protected :

    public :
        AMateria(std::string const &type);
        AMateria();
        ~AMateria();
        AMateria(const AMateria& copy);
        AMateria& operator=(const AMateria& copy);

        std::string const& getType()const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
