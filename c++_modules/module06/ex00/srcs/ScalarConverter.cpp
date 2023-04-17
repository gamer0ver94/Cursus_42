#include "../classes/ScalarConverter.hpp"

void ScalarConverter::convert(std::string target){
	int myInt = (int)target;
	std::cout << static_cast<float>(target) << std::endl;	
}