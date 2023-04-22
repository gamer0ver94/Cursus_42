#include "AForm.hpp"

class Intern{
	private :
		AForm* createRobotomyRequest(std::string target);
		AForm* createShrubberyCreation(std::string target);
		AForm* createPresidentialPardon(std::string target);
	public :
		AForm* makeForm(std::string formName, std::string formTarget);

	class InternException : public std::exception{
		public :
			const char *what() const throw();
	};
};