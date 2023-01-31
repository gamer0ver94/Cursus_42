#include "../classes/Zombie.hpp"

Zombie::Zombie(){
    this->name = "unknown";
    std::cout << GREEN << "Sir.. a Zombie with " << this->name << " name was created!" << WHITE << std::endl;
}

Zombie::Zombie(std::string name){
   this->name = name;
    std::cout << BLUE << "Sir.. a Zombie named " << this->name << " was created!" << WHITE << std::endl;
}

Zombie::~Zombie()
{
    std::cout << RED << "Sir.. i've destroyed this Zombie named " << this->name << "!" << WHITE << std::endl;
}

void Zombie::announce(void)
{
    std::cout << YELLOW << this->name << ":" << "  BraiiiiiiinnnzzzZ..." << WHITE << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name;
    std::cout << CYAN << "Sir.. a Zombie just named himself " << this->name << "!" << WHITE << std::endl;
}