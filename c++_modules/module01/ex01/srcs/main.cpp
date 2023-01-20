#include <iostream>
#include "../classes/Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    int n;

    n = 9;
    zombies = zombieHorde(n, "Ronaldo");
    delete[] zombies;
    return (0);
}