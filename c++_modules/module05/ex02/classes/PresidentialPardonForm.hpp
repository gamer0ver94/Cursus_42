#pragma once
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : virtual public AForm{
	private :
		std::string target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};