#include "classes/Bureaucrat.hpp"
#include <string>
#include <cstdlib>

int main() {
	std::string status;
	std::string name;
	std::string grade;
	std::string method;
	while(1){
		system("clear");
		std::cout << "Enter a name for the Bureaucrat :" << std::endl;
		std::getline(std::cin, name);
		std::cout << "Enter a name for the Bureaucrat grade :" << std::endl;
		std::getline(std::cin, grade);
		system("clear");
		try{
			Bureaucrat bureaucrat(name, std::atoi(grade.c_str()));
			
			std::cout << "press + to increment grade or - to decrement grade ..." << std::endl;
			std::getline(std::cin, method);
			if (method == "+"){
				bureaucrat.incrementGrade();
				std::cout << bureaucrat << std::endl;
			}
			else if (method == "-"){
				bureaucrat.decrementGrade();
				std::cout << bureaucrat << std::endl;
			}
		}
		catch (std::exception &exception){
			std::cout << "Error : " << exception.what() << std::endl;
		}
		std::cout << std::endl << "Type something to CONTINUE ..." << std::endl << "Type EXIT to quit" << std::endl;
		std::getline(std::cin, status);
		if (status == "EXIT" || status == "exit"){
			break;
		}
	}
    return 0;
}
