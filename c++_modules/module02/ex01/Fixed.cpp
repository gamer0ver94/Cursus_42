#include "Fixed.hpp"
#include <iostream>
#include <math.h>

//init static const int
const int Fixed::fractions_bit = 8;

// Default Constructor
Fixed::Fixed(){
	this->fixedPointValue = 0;
	std::cout << GREEN << "Default constructor called" << WHITE << std::endl;
}

//Constructor with int
Fixed::Fixed(int value){
	std::cout << GREEN << "Int constructor called" << WHITE << std::endl;
	this->fixedPointValue = value << this->fractions_bit;
}

//Constructor with float
Fixed::Fixed(const float fixedPointValue){
	std::cout << GREEN << "Float constructor called" << WHITE << std::endl;
	this->fixedPointValue = roundf(fixedPointValue * (1 << this->fractions_bit));
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

// Getter

int Fixed::getRawBits(void) const{
	std::cout << CYAN << "getRawBits member function called" << WHITE << std::endl;
	return (this->fixedPointValue);
}

//Setter

void Fixed::setRawBits(int const raw){
	this->fixedPointValue = raw;
}

//convert from fixed point to float
float Fixed::toFloat(void)const{
	return (static_cast<float>(this->fixedPointValue) / (1 << this->fractions_bit));
}

//convert from fixed point to int
int Fixed::toInt(void)const{
	return fixedPointValue >> fractions_bit;
}

std::ostream& operator<<(std::ostream& output, const Fixed& object) {
    output << object.toFloat();
    return output;
}




