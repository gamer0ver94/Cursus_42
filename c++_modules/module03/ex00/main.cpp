#include "ClapTrap.hpp"

int main(void){
	ClapTrap player1("LL");
	ClapTrap player2("JJ");

	player1.attack(player2.getName());
	return 0;
}