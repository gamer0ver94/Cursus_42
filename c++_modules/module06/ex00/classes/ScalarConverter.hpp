#pragma once
#include <iostream>

class ScalarConverter{
	private :
		char charType;
		int intType;
		float floatType;
		double doubleType;

	public :
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter& operator=(ScalarConverter const &other);
		void convert(std::string input);
		char getCharType(void);
		int	getIntType(void);
		float getFloatType(void);
		double getDoubleType(void);
};

std::ostream& operator<<(std::ostream& output, ScalarConverter &input);