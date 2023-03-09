#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){
	this->name = this->name + ' ' + this->ClapTrap::name;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
	this->hitPoints = FragTrap::hitPoints;
	std::cout << GREEN << "Caracter " << this->ScavTrap::getName() << " was created! (Diamond default contructor)" << WHITE << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), ScavTrap(), FragTrap(){
	this->name = name + ' ' + this->ClapTrap::name;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
	this->hitPoints = FragTrap::hitPoints;
	std::cout << GREEN << "Caracter " << this->name << " was created! (FragTrap default contructor)" << WHITE << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << RED << "Caracter " << this->name << " was dismissed! (DIAMONDTRAP destructor)" << WHITE << std::endl;
}

 DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(), ScavTrap(), FragTrap(){
	this->name = copy.name;
	this->attackDamage = copy.attackDamage;
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
 }

 DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy){
	if (this != &copy){
		this->name = copy.name;
		this->attackDamage = copy.attackDamage;
		this->energyPoints = copy.energyPoints;
		this->hitPoints = copy.hitPoints;
	}
	return *this;
 }

 void DiamondTrap::whoAmI(){
	std::cout << this->ClapTrap::name << std::endl;
 }