#include "../classes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("presidential pardon form", 25, 5), target(target){
    std::cout << GREEN << "presidential pardon form contructor" << WHITE << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << RED << "presidential pardon form destructor" << WHITE << std::endl;
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
    if (executor.getGrade() <= this->getGradeToExecute()){
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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