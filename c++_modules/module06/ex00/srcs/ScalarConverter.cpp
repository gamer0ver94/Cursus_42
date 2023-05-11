#include "../classes/ScalarConverter.hpp"

const std::string ScalarConverter::pseudoLiteral[10] = {"nan", "nanf", "inf", "inff", "+inf", "-inf", "+inff", "-inff", "+nanf", "-nanf"};

char ScalarConverter::charType = 0;
int ScalarConverter::intType = 0;
float ScalarConverter::floatType = 0;
double ScalarConverter::doubleType = 0;

/******* Default Constructor ********/
ScalarConverter::ScalarConverter(){	
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

bool ScalarConverter::isFloat(std::string input){
	int dot = 0;
	for(int i = 0; i < 10; i++){
		if (input == pseudoLiteral[i]){
			return 0;
		}
	}
	for(int i = 0; i < input.length(); i++){
		if (input[i] == '.'){
				dot++;
				if (dot > 1){
					return false;
				}
			}
		if(input[i] == 'f' && input[i - 1] != 'f'){
			if (input[i - 1] && input[i + 1] == '\0'){
				return true;
			}
		}
	}
	return false;
}

bool ScalarConverter::isInt(std::string input){
	try {
        size_t pos;
        int intNb = std::stoi(input, &pos);
        return pos == input.size();
    }
	catch(std::invalid_argument &e){
		return 0;
	}
    catch (std::out_of_range &e) {
        return true;
    }
}

bool ScalarConverter::isChar(std::string input){
    return input.size() == 1 && ((input[0] >= 0 && 127));
}

bool ScalarConverter::isDouble(std::string input){
	size_t size;
	int dot = 0;
	size = input.find('.');
	if (std::string::npos != size){
		try{
				size_t size;
			try{
				for(int i = 0; i < input.length();i++){
					if (input[i] == '.'){
						dot++;
						if (!input[i + 1]){
							return false;
						}
						else if (dot > 1){
							return false;
						}
					}
					if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (!isprint(input[i]) && input[i] != '.')){
						return false;
					}
					if ((input[i] <= 47) && (input[i] >= 33) && (input[i] != '.')){
						return false;
					}
				}
				return std::stod(input);
			}
			catch(std::out_of_range &e){
				std::cout << e.what() << std::endl;
    		    return false;
			}
			return std::stod(input);
		}
		catch(...){
            return 0;
		}
	}
	return 0;
}

char ScalarConverter::getCharType(void){
	return getCharType();
}

void ScalarConverter::printConvertedTypes(std::string input){
	for (int i = 0; i < 10; i++){
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
	else if(intType >= 0 && (intType <= 32 || intType == 127) && doubleType < INT_MAX && doubleType > INT_MIN){
		std::cout << "char: Non displayable"<< std::endl;
	}
	else{
		std::cout << "char: Impossible" << std::endl;
	}
	if (intType != static_cast<int>(floatType) || (doubleType > INT_MAX || doubleType < INT_MIN)){
		std::cout << "int: impossible" << std::endl;
	}
	else{
    	std::cout << "int: " << intType << std::endl;
	}
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
		std::cout << type;
		if (type == "float"){
		
			floatType = std::stof(input);
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
		else if(type == "oor"){
			doubleType = std::stod(input);
			floatType = static_cast<float>(doubleType);
			charType = static_cast<char>(intType);
		}
		printConvertedTypes(type);
	}
	catch(std::exception &e){
		std::cout << "Invalid Input." << std::endl;
	}
}

std::string ScalarConverter::getType(std::string input){
	if (isFloat(input)){
		return "float";
	}
	else if (isDouble(input)){
		return "double";
	}
	else if (isInt(input)){
		try {
			std::stoi(input);
		}
		catch(std::out_of_range &e){
			return "oor";
		}
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
		std::cout << "la";
		throw ScalarConverter::ConverterException();
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