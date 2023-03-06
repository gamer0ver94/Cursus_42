#include "classes/Bureaucrat.hpp"

int main(void){
	try{

		Bureaucrat test("duarte",-1);
		Bureaucrat test1("mmmm",1);
		printf("test1\n");
		

	}
	catch(std::exception &e)
	{
		std::cerr <<e.what() << std::endl;
	}
	printf("test2\n");
	// Bureaucrat test1("mmmm",1);
	return (0);
}