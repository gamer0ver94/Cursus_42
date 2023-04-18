#include "../classes/Intern.hpp"
#include "../classes/RobotomyRequestForm.hpp"
#include "../classes/PresidentialPardonForm.hpp"
#include "../classes/ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(std::string formName, std::string formTarget){
	AForm*form;
	AForm*(*constructors[3])(std::string) = {
		[](std::string formTarget) -> AForm*{return new RobotomyRequestForm(formTarget);},
		[](std::string formTarget) -> AForm*{return new PresidentialPardonForm(formTarget);},
		[](std::string formTarget) -> AForm*{return new ShrubberyCreationForm(formTarget);}
	};
	for(int i = 0; i < 3; i++){
		form = constructors[i](formTarget);
		if (form->getName() == formName){
			std::cout << "The form " << form->getName() << " was createad sucefully!" << std::endl;
			return (form);
		}
		delete form;
	}
	std::cout << "The form " << formName << " was not createad sucefully!" << std::endl;
	return nullptr;
}