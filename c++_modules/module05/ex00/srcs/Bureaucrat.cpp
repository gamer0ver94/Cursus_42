#include "../classes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string setName, unsigned int setGrade)
: name(setName), grade(setGrade){
	std::cout << "Bureaucrat Constructor" << name << std::endl;
	if (grade < 1 || grade > 150){
		(void)setName;
	}
}

Bureaucrat::~Bureaucrat(){

	std::cout<<getName()<<": destructed!\n";
}

const std::string Bureaucrat::getName()const{
	return name;
}

const unsigned int Bureaucrat::getGrade()const{
	return grade;
}

const char* Bureaucrat::Errors::GradeTooHighException()const noexcept{
	return ("Grade Too High");
}

const char* Bureaucrat::Errors::GradeTooLowException()const noexcept{
	return ("Grade Too High");
}

void	Bureaucrat::incrementGrade(){
	try{
		if (grade >= 1 && grade <= 150){
		grade--;
		}
		else{
			throw Errors::GradeTooHighException();
		}
	}
	catch(std::invalid_argument &error){
		std::cerr << "error " << error.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(){
	try{
		if (grade <= 150 && grade >= 1){
		grade++;
		}
		else{
			throw(std::invalid_argument("Error: "));
		}
	}
	catch(std::invalid_argument &error){
		std::cerr << "error " << error.what() << std::endl;
	}
}