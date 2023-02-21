#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
	private:
		int fixedPointValue;
		static const int fractions_bit;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float fixedPointValue);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed &copy);
		~Fixed();

		bool operator>(const Fixed &copy);
		bool operator<(const Fixed &copy);
		bool operator>=(const Fixed &copy);
		bool operator==(const Fixed &copy);
		bool operator!=(const Fixed &copy);
		Fixed& operator+(const Fixed &copy);
		Fixed& operator-(const Fixed &copy);
		Fixed& operator*(const Fixed &copy);
		Fixed& operator/(const Fixed &copy);
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed&first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);

		int getRawBits(void);
		void setRawBits(int const raw);
		float toFloat(void)const;
		int toInt(void)const;
		
};
std::ostream& operator<<(std::ostream & output, Fixed const & object);
#endif