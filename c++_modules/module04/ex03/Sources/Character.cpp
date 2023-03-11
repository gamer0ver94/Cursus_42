#include "../Classes/Character.hpp"

Character::Character(){

}

Character::Character(std::string name){
	this->name = name;
}

Character::~Character(){

}

Character::Character(const Character& copy){
	(void)copy;
}

Character& Character::operator=(const Character& copy){
	(void)copy;
	return *this;
}

std::string const &Character::getName() const{
	return this->name;
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (!this->slots[i]){
			this->slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx){
	(void)idx;
}

void Character::use(int idx, ICharacter& target){
	this->slots[idx]->use(target);
}