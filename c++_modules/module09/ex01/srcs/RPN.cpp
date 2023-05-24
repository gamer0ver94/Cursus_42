#include "../classes/RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){
	inputParser(input);
}

RPN::~RPN(){}

RPN::RPN(const RPN& copy){
	if (this != &copy){

	}
}

RPN& RPN::operator=(const RPN& copy){
	if (this != &copy){
		
	}
	return *this;
}

void RPN::output(){
	std::vector<char>tmp;
	int res = static_cast<int>(container[0] - '0');
	int status = false;
//push values into a temporary container until it found a operator
	for (std::vector<char>::const_iterator it = container.begin(); it != container.end(); ++it){
		if (*it != '+' && *it != '-' && *it != '/' && *it != '*'){
			tmp.push_back(*it);
		}
		else{
			//using the operator it
			for (std::vector<char>::const_iterator iter = tmp.begin(); iter != tmp.end(); ++iter){
				if (status == 0){
					status = true;
					continue;
				}
				switch (*it){
					case '*' :
						std::cout << res << *it << *iter << " = ";
						res *= static_cast<int>(*iter) - '0';
						std::cout << res <<std:: endl;
						break;
					case '/' :
						std::cout << res << *it << *iter << " = ";
						res /= static_cast<int>(*iter) - '0';
						std::cout << res <<std:: endl;
						break;
					case '+' :
						std::cout << res << *it << *iter << " = ";
						res += static_cast<int>(*iter) - '0';
						std::cout << res <<std:: endl;
						break;
					case '-' :
						std::cout << res << *it << *iter << " = ";
						res -= static_cast<int>(*iter) - '0';
						std::cout << res <<std:: endl;
						break;
				}
			}
			tmp.clear();
		}
	}
	std::cout << "the result is "<< res << std::endl;
}

void RPN::inputParser(std::string input){
	std::string str(input);

	for (size_t i = 0; i < str.size(); i++){
		if (str[i] != ' '){
			if (str[i + 1] && str[i + 1] != ' '){
				throw OverNineException();
			}
			container.push_back(str[i]);
		}
	}
}

const char* RPN::OverNineException::what()const throw(){
	return "Input detected number over nine.";
}