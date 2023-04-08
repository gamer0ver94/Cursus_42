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
		fd << "                                                         . \n\
    	                                          .         ;  \n\
    	             .              .              ;%     ;;   \n\
    	               ,           ,                :;%  %;   \n\
    	                :         ;                   :;%;'     .,   \n\
    	       ,.        %;     %;            ;        %;'    ,;\n\
    	         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
    	          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
    	           ;%;      %;        ;%;        % ;%;  ,%;'\n\
    	            `%;.     ;%;     %;'         `;%%;.%;'\n\
    	             `:;%.    ;%%. %@;        %; ;@%;%'\n\
    	                `:%;.  :;bd%;          %;@%;'\n\
    	                  `@%:.  :;%.         ;@@%;'   \n\
    	                    `@%.  `;@%.      ;@@%;         \n\
    	                      `@%%. `@%%    ;@@%;        \n\
    	                        ;@%. :@%%  %@@%;       \n\
    	                          %@bd%%%bd%%:;     \n\
    	                            #@%%%%%:;;\n\
    	                            %@@%%%::;\n\
    	                            %@@@%(o);  . '        \n\
    	                            %@@@o%;:(.,'         \n\
    	                        `.. %@@@o%::;         \n\
    	                           `)@@@o%::;         \n\
    	                            %@@(o)::;        \n\
    	                           .%@@@@%::;         \n\
    	                           ;%@@@@%::;.         \n\
    	                          ;%@@@@%%:;;;. \n\
    	                      ...;%@@@@@%%:;;;;,..";
	}
}