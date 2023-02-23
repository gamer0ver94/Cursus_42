#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <unistd.h>
#include <ctime>

int main(void){
	ScavTrap player1("Jacob");
	ScavTrap player2("Phantom");
	unsigned int random;
	unsigned int round;
	int			energyState[2];

	energyState[0] = 1;
	energyState[1] = 1;
	std::srand(std::time(0));
	round = 0;
	std::cout << "LOADING..." << std::endl;
	sleep(3);
	while (player1.getHitPoints() > 0 && player2.getHitPoints() > 0){
		random = std::rand() % 7;
		system("clear");
		std::cout << BLUE << "Round " << round << WHITE << std::endl;
		round++;
		switch(random){
			case 0 :
				player1.attack(player2.getName());
				if (player1.getEnergyState() == 0)
					energyState[0] = -1;
				else if (energyState[0] == 1)
					player2.takeDamage(player1.getAttackDamage());
				break;
			case 1 :
				player2.attack(player1.getName());
				if (player1.getEnergyState() == 0)
					energyState[1] = -1;
				else if (energyState[1] == 1)
					player2.takeDamage(player1.getAttackDamage());
				player1.takeDamage(player2.getAttackDamage());
				break;
			case 2 :
				std::cout << player1.getName() << " gets bored ..." << std::endl;
				player1.takeDamage(rand() % 50);
				break;
			case 3 :
				std::cout << player2.getName() << " gets bored ..." << std::endl;
				player2.takeDamage(std::rand() % 50);
				break;
			case 4 :
				player1.beRepaired(std::rand() % 10);
				break;
			case 5 :
				player2.beRepaired(std::rand() % 10);
				break;
			case 6 : player1.guardGate();
				break;
			case 7 : player2.guardGate();

		}
		std::cout << "________________________________" << std::endl;
		std::cout << "|  " << player1.getName() << " has " << CYAN << player1.getHitPoints() << WHITE << " hits points!" << std::endl;
		std::cout << "|  " << player2.getName() << " has " << PURPLE << player2.getHitPoints() << WHITE << " hits points!" << std::endl;
		sleep(2);
	}
	return 0;
}