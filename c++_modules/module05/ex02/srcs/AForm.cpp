#include "../classes/AForm.hpp"

// AForm::AForm() : gradeToExecute(5), gradeToSign(10), isSigned(0){
// }

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute)
: name(name), gradeToSign(gradeToSign), isSigned(0), gradeToExecute(gradeToExecute){
}

AForm::~AForm(){
    std::cout << RED << getName() << " was destructed!" << std::endl;
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