#pragma once
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : virtual public AForm{
	private :
		std::string target;
	public :
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};