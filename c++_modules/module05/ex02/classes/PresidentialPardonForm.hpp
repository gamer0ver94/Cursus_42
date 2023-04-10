#pragma once
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : virtual public AForm{
	public :
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};