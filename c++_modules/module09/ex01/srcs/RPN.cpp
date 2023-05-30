#include "../classes/RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){
	std::string str(input);
	expression = str;
	for (size_t i = 0; i < str.size(); i++){
		if (str[i] != ' '){
			if (str[i + 1] && str[i + 1] != ' '){
				throw OverNineException();
			}
		}
	}
}

const char* RPN::OverNineException::what()const throw(){
	return "Invalid Input";
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

// void RPN::operate(std::stack<int> &operation, char op){

// }

void RPN::output(){
	std::stack<int>container;

	for(size_t i = 0; i < expression.size(); i++){
		if (expression[i] == ' '){
			continue;
		}
		if (expression[i] != '+' && expression[i] != '-' && expression[i] != '/' && expression[i] != '*'){
			container.push(static_cast<int>(expression[i] - '0'));
		}
		else{
			if (container.size() < 2){
				throw OverNineException();
			}
			int y = container.top();
			container.pop();
			int x = container.top();
			container.pop();
			int result = 0;
			switch(expression[i])
			{
				case '+' :
					result = x + y;
					break;
				case '/' :
					result = x / y;
					break;
				case '*' :
					result = x * y;
					break;
				case '-' :
					result = x - y;
					break;
			}
			container.push(result);
		}		
	}
	std::cout << container.top() << std::endl;
}
