#pragma once
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : virtual public AForm{
	private :
		std::string target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};