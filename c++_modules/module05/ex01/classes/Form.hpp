#pragma once
#include <iostream>
#include "../classes/Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private :
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    
    public :
        Form();
        Form(std::string name, const int gradeToSign, const int gradeToExecute);
        virtual ~Form();
        // Form(const Form &copy);
        // Form& operator=(const Form &Form);

        void beSigned(Bureaucrat &bureaucrat);
        const std::string getName()const;
        bool getIsSigned()const;
        const int getGradeToSign()const;
        const int getGradeToExecute()const;
};