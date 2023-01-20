#include <iostream>
#include "../classes/Zombie.hpp"

int main(void)
{
    Zombie *zombieOne;
    Zombie *zombieTwo;
    Zombie *zombieThree;

    zombieOne = new Zombie("Messi");
    randomChump("Ronaldo");
    zombieOne->announce();
    zombieTwo = new Zombie("Neymar");
    zombieThree = new Zombie("Mbappe");
    zombieTwo->announce();
    zombieThree->announce();
    delete zombieOne;
    delete zombieTwo;
    delete zombieThree;
    randomChump("God");
    return (0);
}