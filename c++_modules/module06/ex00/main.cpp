#include <iostream>
#include "classes/ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argv[1]){
		ScalarConverter test;

    	test.convert(argv[1]);
	}
    return 0;
}