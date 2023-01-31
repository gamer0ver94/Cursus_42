#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
	private:
		int fixedPointValue;
		static const int fractions_bit;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float fixedPointValue);
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(Fixed &copy);
		~Fixed();

		int getRawBits(void);
		void setRawBits(int const raw);
		float toFloat(void)const;
		int toInt(void)const;
};

#endif