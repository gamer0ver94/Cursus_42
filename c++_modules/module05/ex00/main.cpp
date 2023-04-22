#include "classes/Bureaucrat.hpp"
#include <string>
int main() {
	std::string status;
	std::string name;
	std::string grade;
	std::string method;
	while(status != "exit"){
		system("clear");
		std::cout << "Enter a name for the Bureaucrat :" << std::endl;
		std::getline(std::cin, name);
		std::cout << "Enter a name for the Bureaucrat grade :" << std::endl;
		std::getline(std::cin, grade);
		system("clear");
		try{
			Bureaucrat bureaucrat(name, std::stoi(grade));
			
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
	}
    return 0;
}
