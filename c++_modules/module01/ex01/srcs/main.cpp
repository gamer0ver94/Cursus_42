#include <iostream>
#include "../classes/Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    int n;

    n = 9;
    zombies = zombieHorde(n, "Ronaldo");
	for(int i = 0; i < n; i++){
		zombies[i].announce();
	}
    delete[] zombies;
    return (0);
}