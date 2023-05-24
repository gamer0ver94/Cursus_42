#pragma once
#include <iostream>
#include <vector>

class RPN{
	public :
		RPN(std::string input);
		~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		void output();
	private :
		RPN();
		std::vector<char> container;
		void inputParser(std::string input);
	class OverNineException : public std::exception{
		public :
			const char* what()const throw();
	};
};