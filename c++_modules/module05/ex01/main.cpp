#include "classes/Bureaucrat.hpp"
#include "classes/Form.hpp"

int main() {
	try{
		Bureaucrat *test = new Bureaucrat("Socrates", 151);
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
	Form *form = new Form("Osland University", 50, 50);
	try{
		form->beSigned(*test);
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
	try{
		test->signedForm(*form);
		std::cout << *test << std::endl;
		delete test;
		delete form;
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
    return 0;
}
