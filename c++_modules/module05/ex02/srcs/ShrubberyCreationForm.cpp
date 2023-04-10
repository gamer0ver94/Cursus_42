#include "../classes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() <= getGradeToExecute())
	{
		std::ofstream fd(getName() + " _shrubbery");
		fd << "\033[32m               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
\033[0;35m       |o|        | |         | |\n\
       |.|        | |         | |\n\
 \033[32m\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	}
}