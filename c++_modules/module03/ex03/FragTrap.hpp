#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
    public :
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& copy);

        void highFiveGuys(void);

};

#endif
