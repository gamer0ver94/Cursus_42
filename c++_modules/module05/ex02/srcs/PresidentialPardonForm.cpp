#include "../classes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
AForm("Presidential_Pardon_Form", 25, 5), target("Default"){
	 std::cout << GREEN << " default Presidential_Pardon_Form contructor" << WHITE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("Presidential_Pardon_Form", 25, 5), target(target){
    std::cout << GREEN << "Presidential_Pardon_Form contructor" << WHITE << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << RED << "Presidential_Pardon_Form destructor" << WHITE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
AForm(copy), target(copy.target){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if (this != &copy){
		this->target = copy.target;
	}
	return *this;
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