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
		ScalarConverter();
		static const std::string pseudoLiteral[10];
		bool isInt(std::string input)const;
		bool isFloat(std::string input)const;
		bool isDouble(std::string input)const;
		bool isChar(std::string input)const;
		static std::string getType(std::string input);
		void printConvertedTypes(std::string input);
		char getCharType(void);
		int	getIntType(void);
		float getFloatType(void);
		double getDoubleType(void);
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter& operator=(ScalarConverter const &other);
		// ~ScalarConverter();

	public :
		static void convert(std::string input);
	class ConverterException : public std::exception{
		const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& output, ScalarConverter &input);