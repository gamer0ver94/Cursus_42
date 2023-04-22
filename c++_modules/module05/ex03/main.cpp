#include "classes/Bureaucrat.hpp"
#include "classes/AForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/PresidentialPardonForm.hpp"
#include "classes/Intern.hpp"
#include <string>

int main() {
	AForm* rrf;
	try{
		Bureaucrat la("socrates", 150);
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("shrubbery creation form", "Bender");
		rrf->execute(la);
		delete rrf;

	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
		delete rrf;
	}
    return 0;
}