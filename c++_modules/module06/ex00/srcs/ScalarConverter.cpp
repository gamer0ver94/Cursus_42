#include "../classes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter():
charType(0), intType(0), floatType(0), doubleType(0){	
}

ScalarConverter::ScalarConverter(ScalarConverter const &other){
    if (this != &other){
        *this = other;
    }
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other){
    if (this != &other){
        *this = other;
    }
    return (*this);
}

void ScalarConverter::convert(std::string input){
    try{
        charType = std::stoi(input);
        isprint(static_cast<int>(charType)) ? std::cout << "char : " << charType << std::endl : std::cout << "char : Non displayable" << std::endl;
    }
    catch (const std::exception&){
        std::cout << "char : impossible" << std::endl;
    }
    try{
        intType = std::stoi(input);
        std::cout << "int : " << intType << std::endl;
    }
    catch(const std::exception&){
        std::cout << "int : impossible" << std::endl;
    }
    try{
        floatType = std::stof(input);
        std::cout << "float : " << floatType << "f" << std::endl;
    }
    catch(const std::exception&){
        std::cout << "float : nanf" << std::endl;
    }
    try{
        doubleType = std::stod(input);
        std::cout << "double : " << doubleType << std::endl;
    }
    catch(const std::exception&){
        std::cout << "double : nan" << std::endl;
    }
}

char ScalarConverter::getCharType(void){
    return charType;
}

int	ScalarConverter::getIntType(void){
    return intType;
}

float ScalarConverter::getFloatType(void){
    return floatType;
}

double ScalarConverter::getDoubleType(void){
    return doubleType;
}

std::ostream& operator<<(std::ostream& output, ScalarConverter &input){
    output << input.getCharType() << std::endl << input.getIntType() << std::endl << input.getFloatType() << std::endl << input.getDoubleType();
    return output;
}