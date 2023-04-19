#pragma once
#include <iostream>

class ScalarConverter{
	private :
		char charType;
		int intType;
		float floatType;
		double doubleType;

		bool isInt(std::string input)const;
		bool isFloat(std::string input)const;
		bool isDouble(std::string input)const;
		std::string getType(std::string input)const;

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