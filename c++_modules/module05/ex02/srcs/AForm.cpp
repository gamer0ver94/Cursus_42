#include "../classes/AForm.hpp"

AForm::AForm() :
name("default"), isSigned(0), gradeToSign(100), gradeToExecute(100){
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute)
: name(name), isSigned(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
    std::cout << GREEN << "AForm constructor" << WHITE << std::endl;
}

AForm::~AForm(){
    std::cout << RED << "AForm constructor" << WHITE << std::endl;
}

AForm::AForm(const AForm &copy) : 
name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign),gradeToExecute(copy.gradeToExecute){
	std::cout << GREEN << "copy contructor" << std::endl;
}

AForm& AForm::operator=(const AForm &copy){
	if (this != &copy){
		this->isSigned = copy.isSigned;
	}
	return *this;
}

void AForm::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->getGradeToSign()){
        throw (Bureaucrat::GradeTooLowException());
    }
	else{
		isSigned = 1;
	}
}

const std::string AForm::getName()const{
    return name;
}

bool AForm::getIsSigned()const{
    return isSigned;
}

int AForm::getGradeToSign()const{
    return gradeToSign;
}

int AForm::getGradeToExecute()const{
    return gradeToExecute;
}

const char* AForm::noContractSign::what()const throw(){
	return (RED "Could not execute because no form signed..." WHITE);
}