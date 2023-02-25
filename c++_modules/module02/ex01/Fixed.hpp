#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BBLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

class Fixed{
	private:
		int fixedPointValue;
		static const int fractions_bit;
	public:
		Fixed();
		Fixed(int value);
		Fixed(const float fixedPointValue);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed &copy);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void)const;
		int toInt(void)const;
};
std::ostream& operator<<(std::ostream & output, Fixed const & object);
#endif