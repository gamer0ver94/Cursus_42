#include "../classes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("shrubbery creation form", 145, 137), target(target){
   std::cout << GREEN << "Shrubbery_Creation_Form contructor" << WHITE << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
   std::cout << RED << "Shrubbery_Creation_Form destructor" << WHITE << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() <= getGradeToExecute())
	{
      std::cout << "ShrubberyCreationForm was a success .." << std::endl;
		std::ofstream fd((target + "_shrubbery").c_str());
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
   else{
      if (this->getIsSigned() == 0){
            throw AForm::noContractSign();
      }
      else{
         throw Bureaucrat::GradeTooLowException();
      }
   }
}