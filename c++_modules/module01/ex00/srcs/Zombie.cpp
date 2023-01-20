#include "../classes/Zombie.hpp"

Zombie::Zombie(std::string name){
   this->name = name;
    std::cout << "Sir.. a Zombie named " << this->name << " was created!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Sir.. i've destroyed this Zombie named " << this->name << "!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ":" << "  BraiiiiiiinnnzzzZ..." << std::endl;
}