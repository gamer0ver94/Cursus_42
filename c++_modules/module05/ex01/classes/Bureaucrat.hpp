#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "../classes/Form.hpp"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

class Form;

class Bureaucrat{
	private :
		const std::string name;
		int grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string setName, int setGrade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		const std::string getName()const;
		int getGrade()const;
		void	decrementGrade();
		void	incrementGrade();
		void	signedForm(Form &form);
	class GradeTooHighException : public std::exception{
		public :
			virtual const char* what()const throw();
	};
	class GradeTooLowException : public std::exception{
		public :
			virtual const char* what()const throw();
	};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& obj);

#endif