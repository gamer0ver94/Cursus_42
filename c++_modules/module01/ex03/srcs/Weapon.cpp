#include "../classes/Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(std::string type){
    this->setType(type);
}

Weapon::~Weapon(){

}

void Weapon::setType(std::string type){
    this->type = type;
}

const std::string& Weapon::getType() const{
    return (this->type);
}