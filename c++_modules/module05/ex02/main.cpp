#include "classes/Bureaucrat.hpp"
#include "classes/AForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/PresidentialPardonForm.hpp"
#include <string>
#include <cstdlib>

int main() {
	Bureaucrat test("la", 120);
	Bureaucrat test2 = test;
	test2 = test;

    return 0;
}