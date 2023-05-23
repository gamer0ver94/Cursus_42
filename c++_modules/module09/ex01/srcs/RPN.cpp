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
	int value = 0;
//push values into a temporary container until it found a operator
	for (std::vector<char>::const_iterator it = container.begin(); it !=container.end(); ++it){
		if (*it != '+' || *it != '-' || *it != '/' || *it != '*'){
			tmp.push_back(*it);
			container.erase(container.begin());
		}
		else{
			//using the operator it
			for (std::vector<char>::const_iterator iter = container.begin(); iter !=container.end(); ++iter){
				switch (*container.begin()){
					case '*' :
						value *= static_cast<int>(*tmp.begin());
					case '/' :
						value /= static_cast<int>(*tmp.begin());
					case '+' :
						value += static_cast<int>(*tmp.begin());
					case '-' :
						value -= static_cast<int>(*tmp.begin());
				}
			}
			value = 0;
			container.insert(container.begin(), static_cast<char>(value));
		}
	}
}

void RPN::inputParser(std::string input){
	std::string str(input);

	for (size_t i = 0; i < str.size(); i++){
		if (str[i] != ' '){
			container.push_back(str[i]);
		}
	}
}