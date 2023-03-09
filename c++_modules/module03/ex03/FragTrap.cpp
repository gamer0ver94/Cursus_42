#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap"){
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (FragTrap default contructor)" << WHITE << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (FragTrap contructor)" << WHITE << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy.name){
    this->attackDamage = copy.attackDamage;
    this->energyPoints = copy.energyPoints;
    this->hitPoints = copy.hitPoints;

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