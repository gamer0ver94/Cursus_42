#pragma once
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter{
	private :
		char charType;
		int intType;
		float floatType;
		double doubleType;
		const std::string pseudoLiteral[8] = {"nan", "nanf", "inf", "inff", "+inf", "-inf", "+inff", "-inff"};

		bool isInt(std::string input)const;
		bool isFloat(std::string input)const;
		bool isDouble(std::string input)const;
		bool isChar(std::string input)const;
		std::string getType(std::string input)const;
		void printConvertedTypes(std::string input);

	public :
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter& operator=(ScalarConverter const &other);
		void convert(std::string input);
		char getCharType(void);
		int	getIntType(void);
		float getFloatType(void);
		double getDoubleType(void);
	class ConverterException : public std::exception{
		const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& output, ScalarConverter &input);