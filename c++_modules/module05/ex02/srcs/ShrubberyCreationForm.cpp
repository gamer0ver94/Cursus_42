#include "../classes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137){
	std::cout << "help";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::cout << "help";
}