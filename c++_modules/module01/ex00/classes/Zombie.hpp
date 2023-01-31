#pragma once
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
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump(std::string name);