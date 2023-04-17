#pragma once
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : virtual public AForm{
	private :
		std::string target;
	public :
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};