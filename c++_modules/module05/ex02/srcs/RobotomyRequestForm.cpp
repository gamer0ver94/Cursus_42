#include "../classes/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm(target, 72, 45){
}

RobotomyRequestForm::~RobotomyRequestForm(){

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    srand(std::time(nullptr));
    int random = rand() % 2;
    if (random == 0){
        std::cout << "**DRILL NOISES**  " << executor.getName() << " has been robotomized succefully..." << std::endl;
    }
    else{
        std::cout << "**DRILL NOISES**  " << executor.getName() << " has failed to be robotomized..." << std::endl;
    }
}