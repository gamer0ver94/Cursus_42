#include "../classes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("Presidential_Pardon_Form", 25, 5), target(target){
    std::cout << GREEN << "Presidential_Pardon_Form contructor" << WHITE << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << RED << "Presidential_Pardon_Form destructor" << WHITE << std::endl;
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
    if (executor.getGrade() <= this->getGradeToExecute()){
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else{
        if (this->getIsSigned() == 0){
            std::cout << "error to execute : no contract signed" << std::endl;
        }
        else{
            throw Bureaucrat::GradeTooLowException();
        }
   }
}