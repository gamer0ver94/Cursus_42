#include "classes/Bureaucrat.hpp"
#include "classes/Form.hpp"
#include "classes/Bureaucrat.hpp"
#include <string>

int main() {
	std::string status;
	std::string name;
	std::string grade;
	std::string method;
	std::string formName;
	std::string gradeToSign;
	std::string gradeToExcute;

	while(status != "exit"){
		system("clear");
		std::cout << "Enter a name for the Bureaucrat :" << std::endl;
		std::getline(std::cin, name);
		std::cout << "Enter a name for the Bureaucrat grade :" << std::endl;
		std::getline(std::cin, grade);
		std::cout << "Enter a name for the FORM :" << std::endl;
		std::getline(std::cin, formName);
		std::cout << "Enter a the grade requeriment sign :" << std::endl;
		std::getline(std::cin, gradeToSign);
		std::cout << "Enter a the grade requeriment to execute :" << std::endl;
		std::getline(std::cin, gradeToExcute);
		system("clear");
		try{
			Bureaucrat bureaucrat(name, std::stoi(grade));
			Form form(formName,std::stoi(gradeToSign), std::stoi(gradeToExcute));
			bureaucrat.signedForm(form);
		}
		catch (std::exception &exception){
			std::cout << "Error : " << exception.what() << std::endl;
		}
		std::cout << std::endl << "Type something to CONTINUE ..." << std::endl << "Type EXIT to quit" << std::endl;
		std::getline(std::cin, status);
	}
    return 0;
}
