#pragma once
#include <iostream>
#include <iomanip>
#include <climits>

class ScalarConverter{
	private :
		static char charType;
		static int intType;
		static float floatType;
		static double doubleType;
		ScalarConverter();
		static const std::string pseudoLiteral[10];
		static bool isInt(std::string input);
		static bool isFloat(std::string input);
		static bool isDouble(std::string input);
		static bool isChar(std::string input);
		static std::string getType(std::string input);
		static void printConvertedTypes(std::string input);
		char getCharType(void);
		int	getIntType(void);
		float getFloatType(void);
		double getDoubleType(void);
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter& operator=(ScalarConverter const &other);
		~ScalarConverter();

	public :
		static void convert(std::string input);
	class ConverterException : public std::exception{
		const char * what() const throw();
	};
};
