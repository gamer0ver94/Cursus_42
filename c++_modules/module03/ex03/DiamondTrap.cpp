#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(name), FragTrap(name) {
    this->name = "Unknown";
}

DiamondTrap::DiamondTrap(std::string name){
    this->name = name + "_clap_name";
}

DiamondTrap::~DiamondTrap(){

}