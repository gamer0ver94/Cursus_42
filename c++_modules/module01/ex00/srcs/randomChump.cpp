#include "../classes/Zombie.hpp"
void randomChump(std::string name)
{
    Zombie *zombie;

    zombie = NULL;
    (void)zombie;
    zombie = newZombie(name);
    zombie->announce();
    delete zombie;
}