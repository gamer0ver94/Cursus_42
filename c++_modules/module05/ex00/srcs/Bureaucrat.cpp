#include "../classes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string setName, int setGrade)
: name(setName), grade(setGrade){
	if (setGrade < 1){
		throw GradeTooLowException();
	}
	else if (setGrade > 150){
		throw GradeTooHighException();
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
	try{
		if (grade >= 1 && grade <= 150){
		grade--;
		}
		else{
			throw GradeTooHighException();
		}
	}
	catch(std::exception &error){
		std::cerr << "error " << error.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(){
	if (grade + 1 <= 150 && grade >= 1){
	grade++;
	}
	else{
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& obj){
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return output;
}