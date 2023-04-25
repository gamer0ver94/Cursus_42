#include "../classes/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
AForm("Robotomy_Request_Form", 72, 45), target("default"){
    std::cout << GREEN << "RobotomyRequestForm default contructor" << WHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("Robotomy_Request_Form", 72, 45), target(target){
    std::cout << GREEN << "RobotomyRequestForm contructor" << WHITE << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << RED << "RobotomyRequestForm destructor" << WHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
AForm(copy), target(copy.target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
	if (this != &copy){
		this->target = copy.target;
	}
	return *this;
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