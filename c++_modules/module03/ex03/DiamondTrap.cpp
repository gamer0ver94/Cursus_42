#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    this->name = "Unknown";
	this->ClapTrap::setName(name + ' ' + this->ClapTrap::name); 
	this->setAttackDamage(FragTrap::attackDamage);
	this->setEnergyPoints(ScavTrap::energyPoints);
	this->setHitPoints(FragTrap::hitPoints);
	std::cout << GREEN << "Caracter " << this->ScavTrap::getName() << " was created! (Diamond default contructor)" << WHITE << std::endl;
}

DiamondTrap::DiamondTrap(std::string name){
    this->name = name;
	this->ClapTrap::setName(name + ' ' + this->ClapTrap::name); 
	this->setAttackDamage(FragTrap::attackDamage);
	this->setEnergyPoints(ScavTrap::energyPoints);
	this->setHitPoints(ScavTrap::hitPoints);
	std::cout << GREEN << "Caracter " << this->name << " was created! (FragTrap default contructor)" << WHITE << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << RED << "Caracter " << this->name << " was dismissed! (DIAMONDTRAP destructor)" << WHITE << std::endl;
}

 DiamondTrap::DiamondTrap(const DiamondTrap& copy){
	this->name = copy.name;
	this->setAttackDamage(copy.attackDamage);
	this->setEnergyPoints(copy.energyPoints);
	this->setHitPoints(copy.hitPoints);
 }

 DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy){
	if (this != &copy){
		this->name = copy.name;
		this->setAttackDamage(copy.attackDamage);
		this->setEnergyPoints(copy.energyPoints);
		this->setHitPoints(copy.hitPoints);
	}
	return *this;
 }

 void DiamondTrap::whoAmI(){
	std::cout << this->ClapTrap::name << std::endl;
 }