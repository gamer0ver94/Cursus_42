#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <string>

#include "generic/easyfind.hpp"
int main() {
	std::string line;
    std::vector<int> test;
	std::string elem;
	system("clear");
	while (1){
		std::cout << " PLEASE ENTER ONE ELEMENT AT A TIME // TYPE <DONE> WHEN IT FINISHED" << std::endl;
		std::getline(std::cin,  line);
		if (line == "DONE"){
			break;
		}
		try{
			test.push_back(std::stoi(line));
		}
		catch(...){
		}
		system("clear");
	}
	while (1)
	{
		std::cout << "TYPE A ELEMENT VALUE TO SEARCH" << std::endl;
		std::getline(std::cin, elem);
		 try {
       		 std::vector<int>::iterator it = easyfind(test, std::stoi(elem));
       		 std::cout << "Value found in vector at index " << it - test.begin() << std::endl;
    	}
   		 catch (std::exception& e) {
       		 std::cout << e.what() << std::endl;
   	 }
	}
   
    return 0;
}
