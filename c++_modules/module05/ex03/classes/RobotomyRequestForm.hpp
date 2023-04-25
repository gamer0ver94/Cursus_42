#pragma once
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : virtual public AForm{
	private :
		std::string target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};