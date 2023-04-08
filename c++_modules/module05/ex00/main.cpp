#include "classes/Bureaucrat.hpp"

int main() {
	try{
		Bureaucrat test("Socrates", 150);
		test.decrementGrade();
		std::cout << test << std::endl;
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
	try{
		Bureaucrat test("Socrates", 151);
		test.decrementGrade();
		std::cout << test << std::endl;
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
	try{
		Bureaucrat test("Socrates", 1);
		test.incrementGrade();
		std::cout << test << std::endl;
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
    return 0;
}
