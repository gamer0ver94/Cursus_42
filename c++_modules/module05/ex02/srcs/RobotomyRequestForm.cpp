#include "../classes/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("Robotomy_Request_Form", 72, 45), target(target){
    std::cout << GREEN << "RobotomyRequestForm contructor" << WHITE << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << RED << "RobotomyRequestForm destructor" << WHITE << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    srand(std::time(NULL));
    int random = rand() % 2;
    if (executor.getGrade() <= this->getGradeToExecute()){
        if (random == 0){
        std::cout << "**DRILL NOISES**  " << this->target << " has been robotomized succefully..." << std::endl;
        }
        else{
            std::cout << "**DRILL NOISES**  " << this->target << " has failed to be robotomized..." << std::endl;
        }
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