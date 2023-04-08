#include "classes/Bureaucrat.hpp"
#include "classes/AForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"

int main() {
	try{
		AForm *form = new ShrubberyCreationForm("home");
		Bureaucrat *test = new Bureaucrat("Socrates",151);
		test->signedForm(*form);
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
    return 0;
}
