#include "../classes/Form.hpp"

Form::Form() : isSigned(0), gradeToSign(10), gradeToExecute(5){
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute)
: name(name), isSigned(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
}

Form::~Form(){
    std::cout << RED << getName() << " was destructed!" << std::endl;
}

Form::Form(const Form &copy) : 
name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign),gradeToExecute(copy.gradeToExecute){
	std::cout << GREEN << "copy contructor" << std::endl;
}

Form& Form::operator=(const Form &copy){
	if (this != &copy){
		this->isSigned = copy.isSigned;
	}
	return *this;
}

void Form::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->getGradeToSign()){
        throw (Bureaucrat::GradeTooLowException());
    }
	else{
		isSigned = 1;
	}
}

const std::string Form::getName()const{
    return name;
}

bool Form::getIsSigned()const{
    return isSigned;
}

int Form::getGradeToSign()const{
    return gradeToSign;
}

int Form::getGradeToExecute()const{
    return gradeToExecute;
}