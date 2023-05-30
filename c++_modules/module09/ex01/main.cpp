#include <iostream>
#include "classes/RPN.hpp"
int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << YELLOW << "Multiple arguments detected, insert only one!" << RESET << std::endl;
		return -1;
	}
	try{
		RPN *rpn = new RPN(argv[1]);
		rpn->output();
		delete rpn;
	}
	catch(std::exception &e){
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	
	return 0;
}
