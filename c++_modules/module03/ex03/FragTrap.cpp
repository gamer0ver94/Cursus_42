#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (FragTrap default contructor)" << WHITE << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->setAttackDamage(30);
    this->setEnergyPoints(100);
    this->setHitPoints(100);
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (FragTrap contructor)" << WHITE << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << RED << "Caracter " << this->getName() << " was dismissed! (FRAGTRAP destructor)" << WHITE << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy){
    if (this != &copy){
       this->setHitPoints(copy.getHitPoints());
       this->setEnergyPoints(copy.getHitPoints());
       this->setAttackDamage(copy.getAttackDamage());
    }
    return *this;
}

void FragTrap::highFiveGuys(void){
    std::cout << this->getName() << "uses \'hi five guys\'" << WHITE << std::endl;
}