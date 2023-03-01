#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : ICharacter{
    private :
        std::string name;
        AMateria *slots[4];

    public :
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character& copy);
        Character& operator=(const Character& copy);

        std::string const & getName() const;
        void equip(AMateria* m);
		void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif