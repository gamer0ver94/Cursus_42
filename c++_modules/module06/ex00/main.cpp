#include <iostream>
#include "classes/ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 1 && argv[1]){
		try{
    		ScalarConverter::convert(argv[1]);
		}
		catch(...){

		}
	}
    return 0;
}