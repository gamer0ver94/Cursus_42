#include "../classes/Bureaucrat.hpp"
#include "../classes/AForm.hpp"

Bureaucrat::Bureaucrat(std::string setName, int setGrade)
: name(setName), grade(setGrade){
	if (setGrade < 1){
		throw GradeTooHighException();
	}
	else if (setGrade > 150){
		throw GradeTooLowException();
	}
	else{
		std::cout << GREEN << "Bureaucrat Constructor " << name << WHITE << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){
	std::cout << RED <<getName()<< " was destructed!" << WHITE << std::endl;
}

const std::string Bureaucrat::getName()const{
	return name;
}

const unsigned int Bureaucrat::getGrade()const{
	return grade;
}

const char* Bureaucrat::GradeTooHighException::what()const throw(){
	return (RED "Grade Too High" WHITE);
}

const char* Bureaucrat::GradeTooLowException::what()const throw(){
	return (RED "Grade Too Low" WHITE);
}

void	Bureaucrat::incrementGrade(){
	if (grade - 1 >= 1 && grade - 1 <= 150){
	grade--;
	}
	else{
		throw GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade(){
	if (grade + 1 <= 150 && grade + 1 >= 1){
	grade++;
	}
	else{
		throw GradeTooLowException();
	}
}

void	Bureaucrat::signedForm(AForm &form){
	try{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &exception){
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& obj){
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return output;
}