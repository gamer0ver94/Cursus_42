#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (SCAVTRAP default constructor)" << WHITE << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << GREEN << "Caracter " << this->getName() << " was created! (SCAVTRAP constructor)" << WHITE << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy.name){
    this->attackDamage = copy.attackDamage;
    this->energyPoints = copy.energyPoints;
    this->hitPoints = copy.hitPoints;
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