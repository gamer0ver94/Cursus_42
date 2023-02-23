#include "ClapTrap.hpp"

//_______________DEFAULT CONSTRUCTOR____________

ClapTrap::ClapTrap(){
	this->name = "unknown";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << GREEN << "Caracter " << this->name << " was created! (CLAPTRAP default constructor)" << WHITE << std::endl; 
}

//_________________CONSTRUCTOR__________________

ClapTrap::ClapTrap(std::string name){
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << GREEN << "Caracter " << this->name << " was created! (CLAPTRAP constructor)" << WHITE << std::endl; 
}

//__________________DESTRUCTOR____________________

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Caracter " << this->name << " was dismissed! (CLAPTRAP destructor)" << WHITE << std::endl; 
}

//________________COPY CONSTRUCTOR__________________

ClapTrap::ClapTrap(const ClapTrap& copy){
	this->name = copy.name;
	this->attackDamage = copy.attackDamage;
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
}

//________________COPY ASSIGNMENT OPERATOR____________

ClapTrap& ClapTrap::operator=(const ClapTrap& copy){
	if (this != &copy){
		this->attackDamage = copy.attackDamage;
		this->energyPoints = copy.energyPoints;
		this->hitPoints = copy.hitPoints;
	}
	return (*this);
}

//________________ATTACK MEMBER FUNCTION______________

void ClapTrap::attack(const std::string& target){
	if (this->energyPoints > 0){
		this->energyPoints--;
		std::cout << YELLOW << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << WHITE << std::endl;
	}
	else{
		std::cout << RED << this->name << " have no energy to attack " << WHITE << std::endl;
	}

}

//________________TAKEDAMAGE MEMBER FUNCTION______________

void ClapTrap::takeDamage(unsigned int amount){
	this->hitPoints -= amount;
	std::cout << YELLOW << this->name << " lost " << amount << " hit points!" << WHITE << std::endl;
	if (this->hitPoints < 0)
		std::cout << RED << this->name << " died " << WHITE << std::endl;
}

//________________BEREPAIRED MEMBER FUNCTION______________

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints > 0){
		this->hitPoints +=amount;
		this->energyPoints--;
		std::cout << YELLOW << this->name << " repareid himself " << amount << " hit points!" << WHITE << std::endl;
	}
	else{
		
	}
}

//________________GETTER NAME MEMBER FUNCTION______________

std::string ClapTrap::getName(void)const{
	return this->name;
}

//________________GETTER ATACK DAMAGE MEMBER FUNCTION______________

int ClapTrap::getAttackDamage(void)const{
	return this->attackDamage;
}

//________________GETTER HITPOINTS MEMBER FUNCTION______________

int ClapTrap::getHitPoints(void)const{
	return this->hitPoints;
}

//________________GETTER ENERGY POINTS MEMBER FUNCTION
int ClapTrap::getEnergyState(void)const{
	return this->energyPoints;
}

//________________SETTER HITPOINTS MEMBER FUNCTION______________

void ClapTrap::setHitPoints(unsigned int hitPoints){
	this->hitPoints = hitPoints;
}

//________________SETTER ATTACK DAMAGE MEMBER FUNCTION______________

void ClapTrap::setAttackDamage(unsigned int attackDamage){
	this->attackDamage = attackDamage;
}

//________________SETTER ENERGY POINTS MEMBER FUNCTION______________

void ClapTrap::setEnergyPoints(unsigned int energyPoints){
	this->energyPoints = energyPoints;
}