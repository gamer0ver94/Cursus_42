#pragma once
#include <iostream>
#include "../classes/Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private :
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    
    public :
        AForm(std::string name, const int gradeToSign, const int GradeToExecute);
        virtual ~AForm();
        // Form(const Form &copy);
        // Form& operator=(const Form &Form);

        void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
        const std::string getName()const;
        bool getIsSigned()const;
        const int getGradeToSign()const;
        const int getGradeToExecute()const;
};