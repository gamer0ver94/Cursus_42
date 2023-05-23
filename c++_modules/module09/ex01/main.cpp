#include <iostream>
#include "classes/RPN.hpp"
int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Multiple arguments detected, insert only one!" << std::endl;
		return -1;
	}
	RPN *rpn = new RPN(argv[1]);
	rpn->output();
	delete rpn;
	return 0;
}
