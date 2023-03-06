#include "../classes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string setName, unsigned int setGrade)
: name(setName), grade(setGrade){
	std::cout << "Bureaucrat Constructor" << name << std::endl;
	if (grade < 1 || grade > 150){
		throw(std::invalid_argument("dsad"));
		// throw(myError());
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

void	Bureaucrat::decrementGrade(){
	if (grade >= 1 && grade <= 150){
		grade++;
	}
}

void	Bureaucrat::incrementGrade(){
	try{
		if (grade >= 1 && grade <= 150){
		grade--;
		}
		else{
			throw(std::invalid_argument("this values is not good"));
		}
	}
	catch(std::invalid_argument &error){
		std::cerr << "error " << error.what() << std::endl;
	}
	
}