#include "../classes/AForm.hpp"

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute)
: name(name), gradeToSign(gradeToSign), isSigned(0), gradeToExecute(gradeToExecute){
    std::cout << GREEN << "AForm constructor" << WHITE << std::endl;
}

AForm::~AForm(){
    std::cout << RED << "AForm constructor" << WHITE << std::endl;
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

const int AForm::getGradeToSign()const{
    return gradeToSign;
}

const int AForm::getGradeToExecute()const{
    return gradeToExecute;
}

const char* AForm::noContractSign::what()const throw(){
	return (RED "Could not execute because no form signed..." WHITE);
}