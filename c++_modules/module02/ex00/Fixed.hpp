#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
	private:
		int value;
		static const int fract_bit;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(Fixed &copy);
		~Fixed();

		int getRawBits(void);
		void setRawBits(int const raw);
};

#endif