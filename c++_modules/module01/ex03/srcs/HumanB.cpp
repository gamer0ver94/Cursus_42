#include "../classes/HumanB.hpp"

HumanB::HumanB(){

}

HumanB::HumanB(std::string name){
    this->name = name;
}

HumanB::~HumanB(){

}

void    HumanB::attack(){
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}