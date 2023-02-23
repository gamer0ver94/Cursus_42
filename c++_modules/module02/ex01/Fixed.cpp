#include "Fixed.hpp"
#include <iostream>
#include <math.h>

//init static const int
const int Fixed::fractions_bit = 8;

// Default Constructor
Fixed::Fixed(){
	this->fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

//Constructor with int
Fixed::Fixed(int value){
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << this->fractions_bit;
}

//Constructor with float
Fixed::Fixed(const float fixedPointValue){
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(fixedPointValue * (1 << this->fractions_bit));
}

// Destructor
Fixed::~Fixed(){
	std::cout << "Destructor" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed&copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Copy assignment operator overloading
Fixed& Fixed::operator=(const Fixed& copy){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy){
		this->fixedPointValue = copy.fixedPointValue;
	}
	return (*this);
}

int Fixed::getRawBits(void){
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

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


