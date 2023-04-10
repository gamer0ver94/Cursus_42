#pragma once
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : virtual public AForm{
	public :
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};