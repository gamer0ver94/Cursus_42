#include "classes/Bureaucrat.hpp"
#include "classes/AForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/PresidentialPardonForm.hpp"
#include <string>
#include <cstdlib>

int main() {
	std::string status;
	std::string name;
	std::string grade;
	std::string formNumber;
	std::string formTarget;

	while(1){
		system("clear");
		std::cout << "Enter a name for the Bureaucrat :" << std::endl;
		std::getline(std::cin, name);
		std::cout << "Enter a name for the Bureaucrat grade :" << std::endl;
		std::getline(std::cin, grade);
		std::cout << "Enter a Form : (1)RobotomuRequestForm (2)PresidentialPardonForm (3)ShrubberyCreationForm" << std::endl;
		std::getline(std::cin, formNumber);
		std::cout << "Enter a the form target:" << std::endl;
		std::getline(std::cin, formTarget);
		system("clear");
		try{
			Bureaucrat bureaucrat(name, std::atoi(grade.c_str()));
			switch (std::atoi(formNumber.c_str())){
				case 2 :{
					PresidentialPardonForm form1(formTarget);
					bureaucrat.signedForm(form1);
					form1.execute(bureaucrat);
					break;
				}
				case 3 :{
					ShrubberyCreationForm form2(formTarget);
					bureaucrat.signedForm(form2);
					form2.execute(bureaucrat);
					break;
				}
				case 1 :{
					RobotomyRequestForm form3(formTarget);
					bureaucrat.signedForm(form3);
					form3.execute(bureaucrat);
					break;
				}
			}
		}
		catch (std::exception &exception){
			std::cout << "Error : " << exception.what() << std::endl;
		}
		std::cout << std::endl << "Type something to CONTINUE ..." << std::endl << "Type EXIT to quit" << std::endl;
		std::getline(std::cin, status);
		if (status == "EXIT" || status == "exit"){
			break;
		}
	}
    return 0;
}