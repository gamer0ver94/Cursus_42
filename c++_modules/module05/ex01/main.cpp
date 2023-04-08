#include "classes/Bureaucrat.hpp"
#include "classes/Form.hpp"

int main() {
	try{
		Form *form = new Form("Osland University", 50, 50);
		Bureaucrat *test = new Bureaucrat("Socrates",151);
		test->signedForm(*form);
	}
	catch(std::exception &exception){
		std::cout << YELLOW << "error: " << exception.what() << std::endl;
	}
    return 0;
}
