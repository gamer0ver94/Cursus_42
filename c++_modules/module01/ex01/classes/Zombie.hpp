#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#define WHITE "\033[0;37m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"

class Zombie{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name);

#endif