#include "../classes/Intern.hpp"
#include "../classes/RobotomyRequestForm.hpp"
#include "../classes/PresidentialPardonForm.hpp"
#include "../classes/ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(std::string formName, std::string formTarget){
	std::string a = "PresidentialPardonForm";
	AForm *form = new RobotomyRequestForm(formTarget);
	AForm *form2 = new PresidentialPardonForm(formTarget);
	AForm *form3 = new ShrubberyCreationForm(formTarget);
	return (formName == form->getName()) ? form : (formName == form2->getName() ? form2 : (formName == form3->getName() ? form3 : throw Bureaucrat::GradeTooHighException()));
}