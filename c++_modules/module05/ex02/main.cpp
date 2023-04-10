#include "classes/Bureaucrat.hpp"
#include "classes/AForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/PresidentialPardonForm.hpp"

int main() {
	try{
		AForm *form = new PresidentialPardonForm("home");
		Bureaucrat *test = new Bureaucrat("Socrates",10);
		test->signedForm(*form);
		test->executeForm(*form);
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
    return 0;
}
