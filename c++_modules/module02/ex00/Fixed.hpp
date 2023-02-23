#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
	private:
		int fixedPointValue;
		static const int fractions_bit;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(Fixed &copy);
		~Fixed();

		int getRawBits(void);
		void setRawBits(int const raw);
};

#endif