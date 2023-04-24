#include "../classes/Intern.hpp"
#include "../classes/RobotomyRequestForm.hpp"
#include "../classes/PresidentialPardonForm.hpp"
#include "../classes/ShrubberyCreationForm.hpp"

AForm* Intern::createRobotomyRequest(std::string target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreation(std::string target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardon(std::string target){
	return new PresidentialPardonForm(target);
}

const char * Intern::InternException::what() const throw(){
	return "Could not make this form because it doesnt exist";
}

AForm* Intern::makeForm(std::string formName, std::string formTarget){
	

	typedef AForm* (Intern::*FormCreator)(std::string);
	AForm* result;
	FormCreator funcPtr[3] = {
    &Intern::createPresidentialPardon,
    &Intern::createRobotomyRequest,
    &Intern::createShrubberyCreation
};

	for (int i = 0; i < 3; i++){
		result = (this->*funcPtr[i])(formTarget);
		if (result->getName() == formName){
			std::cout << "successfull.." << std::endl;
			return result;
		}
		else{
			delete result;
		}
	}
	throw Intern::InternException();
	return NULL;
}