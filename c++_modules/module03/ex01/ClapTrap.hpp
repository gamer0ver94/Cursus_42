#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>


class ClapTrap{
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		unsigned int attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& copy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void)const;
		int getAttackDamage(void)const;
		int getHitPoints(void)const;
		int getEnergyState(void)const;

		void setAttackDamage(unsigned int attackDamage);
		void setHitPoints(unsigned int hitPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setName(std::string name);
};

#endif