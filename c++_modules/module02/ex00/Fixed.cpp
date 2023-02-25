#include "Fixed.hpp"
#include <iostream>

//init static const int
const int Fixed::fractions_bit = 8;

// Constructor
Fixed::Fixed(){
	this->fixedPointValue = 0;
	std::cout << GREEN << "Default constructor called" << WHITE << std::endl;
}
// Destructor
Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << WHITE << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& copy){
	std::cout << GREEN << "Copy constructor called" << WHITE << std::endl;
	this->fixedPointValue = copy.getRawBits();
}

// Copy assignment operator overloading
Fixed& Fixed::operator=(const Fixed& copy){
	std::cout << YELLOW << "Copy assignment operator called" << WHITE << std::endl;
	if (this != &copy){
		this->fixedPointValue = copy.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const{
	std::cout << CYAN << "getRawBits member function called" << WHITE << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw){
	this->fixedPointValue = raw;
}






