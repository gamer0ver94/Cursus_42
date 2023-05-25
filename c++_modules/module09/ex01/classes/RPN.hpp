#pragma once
#include <iostream>
#include <stack>

class RPN{
	public :
		RPN(std::string input);
		~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		void output();
	private :
		RPN();
		// void operate(std::stack<int>& operation, char op);
	std::string expression;
	class OverNineException : public std::exception{
		public :
			const char* what()const throw();
	};
};