#include "../classes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::ofstream fd(getName() + " _shrubbery");
	fd << "hellow";
}