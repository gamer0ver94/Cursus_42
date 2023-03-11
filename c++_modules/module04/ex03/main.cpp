#include "Classes/AMateria.hpp"
#include "Classes/Ice.hpp"
#include "Classes/Character.hpp"

int main(void){
	Character *player = new Character("Paul");
	std::cout << player->getName() << std::endl;
	return 0;
}