#pragma once
#include <iostream>
#include <stack>
#define RESET   "\033[0m"   
#define RED     "\033[31m"
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m" 
#define WHITE   "\033[37m"

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