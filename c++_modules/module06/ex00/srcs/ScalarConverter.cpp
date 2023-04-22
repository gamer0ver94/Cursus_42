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

/*******Exception not literal**********/
const char* ScalarConverter::ConverterException::what() const throw(){
	return "This String is not a literal..";
}


/******* isFloat method ********/

bool ScalarConverter::isFloat(std::string input)const{
	for(int i = 0; i < 8; i++){
		if (input == pseudoLiteral[i]){
			return 0;
		}
	}
	try{
        float value = std::stof(input);
		return input.back() == 'f' && std::abs(value) > 0.0f;
	}
	catch (std::exception &e){
        return 0;
	}
}

bool ScalarConverter::isInt(std::string input)const{
	try {
        size_t pos;
        int intNb = std::stoi(input, &pos);
        if (pos != input.length())
            return false;
        return (intNb >= std::numeric_limits<int>::min() && intNb <= std::numeric_limits<int>::max());
    }
    catch (...) {
        return false;
    }
}

bool ScalarConverter::isChar(std::string input)const{
    return input.size() == 1 && ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'));
}

bool ScalarConverter::isDouble(std::string input)const{
	size_t size;
	size = input.find('.');
	if (std::string::npos != size && input.back() != 'f'){
		try{
			return std::stod(input);
		}
		catch(std::exception &e){
            return 0;
		}
	}
	return 0;
}

char ScalarConverter::getCharType(void){
	return getCharType();
}

void ScalarConverter::printConvertedTypes(std::string input){
	std::cout << input << std::endl;
	for (int i = 0; i < 8; i++){
			if (input == pseudoLiteral[i]){
				std::cout << "char: Impossible" << std::endl;
				std::cout << "int: Impossible" << std::endl;
				std::cout << "float:" << input + "f" << std::endl;
				std::cout << "double:" << input << std::endl;
				return;
			}
		}
	if (intType >= 32 && intType <= 126 ){
    	std::cout << "char: " << charType << std::endl;
	}
	else if(intType >= 0 && intType <= 32 || intType == 127){
		std::cout << "char: Non displayable"<< std::endl;
	}
	else{
		std::cout << "char: Impossible" << std::endl;
	}
    std::cout << "int: " << intType << std::endl;
	if (floatType == intType){
		std::cout << std::fixed << std::setprecision(1) << "float: " << floatType << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << doubleType<< std::endl;
	}
	else{
		std::cout << "float: " << floatType << "f" << std::endl;
   		std::cout << "double: " << doubleType << std::endl;
	}
}

/******* Convert Method ********/
void ScalarConverter::convert(std::string input){
	try{
		std::string type = getType(input);
		if (type == "float"){
		
			floatType = std::stof(input) / 1.0;
      		doubleType = static_cast<float>(floatType);
      		intType = static_cast<int>(floatType);
      		charType = static_cast<char>(intType);
		}
		else if(type == "double"){
			doubleType = std::stod(input);
			floatType = static_cast<float>(doubleType);
			intType = static_cast<int>(doubleType);
			charType = static_cast<char>(intType);
		}
		else if (type == "int"){
			intType = std::stoi(input);
			floatType = static_cast<float>(intType);
			doubleType = static_cast<double>(intType);
			charType = static_cast<char>(intType);
		}
		else if(type == "char"){
			charType = input[0];
			intType = static_cast<int>(charType);
			doubleType = static_cast<double>(charType);
			floatType = static_cast<float>(charType);
		}
		printConvertedTypes(type);
			// isFloat(input) ? std::cout << "its a float" << std::endl : std::cout << "not a float" << std::endl;
			// isDouble(input) ? std::cout << "its a Double" << std::endl : std::cout << "not a double" << std::endl;
			// isInt(input) ? std::cout << "its a Int" << std::endl : std::cout << "not a Int" << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
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
	else if (input.size() > 1){
		for (int i = 0; i < 8; i++){
			if (input == pseudoLiteral[i]){
				if(input.back() == 'f' && input[input.length() - 2] == 'f'){
					return input.substr(0, input.length() - 1);
				}
				return pseudoLiteral[i];
			}
		}
		throw ScalarConverter::ConverterException();
	}
	else if (isChar(input)){
		return "char";
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