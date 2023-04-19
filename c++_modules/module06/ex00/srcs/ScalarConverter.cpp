#include "../classes/ScalarConverter.hpp"

/******* Default Constructor ********/
ScalarConverter::ScalarConverter():
charType(0), intType(0), floatType(0), doubleType(0){	
}
/******* Copy Constructor ********/
ScalarConverter::ScalarConverter(ScalarConverter const &other){
    if (this != &other){
        *this = other;
    }
}
/******* Sign Operator Constructor ********/
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other){
    if (this != &other){
        *this = other;
    }
    return (*this);
}

/******* isFloat method ********/

bool ScalarConverter::isFloat(std::string input)const{
	try{
		return std::stof(input) && input.back() == 'f';
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}

bool ScalarConverter::isInt(std::string input)const{
	if (!isFloat(input) && !isDouble(input)){
		try{
			return std::stoi(input);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

bool ScalarConverter::isDouble(std::string input)const{
	size_t size;
	size = input.find('.');
	if (std::string::npos != size && input.back() != 'f'){
		try{
			return std::stod(input);
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

char ScalarConverter::getCharType(void){
	return getCharType();
}

/******* Convert Method ********/
void ScalarConverter::convert(std::string input){
	std::string type = getType(input);

	if (type)
	isFloat(input) ? std::cout << "its a float" << std::endl : std::cout << "not a float" << std::endl;
	isDouble(input) ? std::cout << "its a Double" << std::endl : std::cout << "not a double" << std::endl;
	isInt(input) ? std::cout << "its a Int" << std::endl : std::cout << "not a Int" << std::endl;
}

std::string ScalarConverter::getType(std::string input)const{
	if (isFloat(input)){
		return "float";
	}
	else if (isDouble(input)){
		return "double";
	}
	else if (isInt(input)){
		return "int";
	}
	else{
		return "impossible";
	}
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