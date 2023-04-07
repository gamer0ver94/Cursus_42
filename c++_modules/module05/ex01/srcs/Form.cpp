#include "../classes/Form.hpp"

Form::Form() : gradeToExecute(5), gradeToSign(10), isSigned(0){
}

Form::Form(std::string name, const int gradeToSign, const int GradeToExecute)
: name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign), isSigned(0){
}

Form::~Form(){
    std::cout << RED << getName() << " was destructed!" << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat){
        if (bureaucrat.getGrade() > this->getGradeToSign()){
            throw (Bureaucrat::GradeTooLowException());
        }
}

const std::string Form::getName()const{
    return name;
}

bool Form::getIsSigned()const{
    return isSigned;
}

const int Form::getGradeToSign()const{
    return gradeToSign;
}

const int Form::getGradeToExecute()const{
    return gradeToExecute;
}