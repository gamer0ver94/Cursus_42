#include <iostream>
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

class Bureaucrat{
	private :
		const std::string name;
		unsigned int grade;
	public :
		Bureaucrat(std::string setName, unsigned int setGrade);
		~Bureaucrat();
		const std::string getName()const;
		const unsigned int getGrade()const;
		void	decrementGrade();
		void	incrementGrade();

	class myError:public std::exception{

		const char* what() const throw(){
			
			return "TooLowNumber";
		}
	};
};