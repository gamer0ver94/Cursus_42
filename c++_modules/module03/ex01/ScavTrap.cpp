#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (SCAVTRAP default constructor)" << WHITE << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->setAttackDamage(20);
    this->setEnergyPoints(50);
    this->setHitPoints(100);
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (SCAVTRAP constructor)" << WHITE << std::endl; 
}
ScavTrap::~ScavTrap(){
    std::cout << RED << "Caracter " << this->getName() << " was dismissed! (SCAVTRAP destructor)" << WHITE << std::endl;
}

void ScavTrap::attack(const std::string& target){
    std::cout << YELLOW << "__ScavTrap__ " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << WHITE << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << this->getName() << " is now in KEPPER MODE!" << std::endl;
}