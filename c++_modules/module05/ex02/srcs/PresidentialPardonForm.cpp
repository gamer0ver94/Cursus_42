#include "../classes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm(target, 25, 5){
}
PresidentialPardonForm::~PresidentialPardonForm(){

}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}