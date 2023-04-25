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
		AForm();
        AForm(std::string name, const int gradeToSign, const int GradeToExecute);
        virtual ~AForm();
       AForm(const AForm &copy);
        AForm& operator=(const AForm &copy);

        void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
        const std::string getName()const;
        bool getIsSigned()const;
        int getGradeToSign()const;
        int getGradeToExecute()const;
		class noContractSign : public std::exception{
			public :
				virtual const char* what()const throw();
		};
};