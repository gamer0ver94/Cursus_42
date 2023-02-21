#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name){
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Caracter " << this->name << " was created! (constructor)" << std::endl; 
}

ClapTrap::~ClapTrap()
{
	std::cout << "Caracter " << this->name << " was dismissed! (destructor)" << std::endl; 
}

void ClapTrap::attack(const std::string& target){
	this->energyPoints--;
	std::cout << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	this->hitPoints -= amount;
	std::cout << this->name << " lost " << amount << "hit points!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	this->hitPoints +=amount;
	this->energyPoints--;
	std::cout << this->name << " repareid himself " << amount << "hit points!" << std::endl;
}

std::string ClapTrap::getName(void){
	return this->name;
}