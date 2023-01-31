#include "Fixed.hpp"
#include <iostream>

//init static const int
const int Fixed::fractions_bit = 8;

// Constructor
Fixed::Fixed(){
	this->fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}
// Destructor
Fixed::~Fixed(){
	std::cout << "Destructor" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed&copy){
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = copy.fixedPointValue;
}

// Copy assignment operator overloading
Fixed& Fixed::operator=(Fixed &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy){
		return (*this);
	}
	return (copy);
}

int Fixed::getRawBits(void){
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw){
	this->fixedPointValue = raw;
}






