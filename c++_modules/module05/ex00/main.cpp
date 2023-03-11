#include "classes/Bureaucrat.hpp"

int main() {
    try {
        // Create a bureaucrat with a valid grade
        Bureaucrat bureaucrat1("John", 75);
        std::cout << "Bureaucrat " << bureaucrat1.getName() << " created with grade " << bureaucrat1.getGrade() << std::endl;

        // Try to create a bureaucrat with an invalid grade (too low)
        Bureaucrat bureaucrat2("Jane", 0);
        std::cout << "Bureaucrat " << bureaucrat2.getName() << " created with grade " << bureaucrat2.getGrade() << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cerr << RED << "Error: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << std::endl;
    }
    
    // Test decrementing and incrementing grades
    Bureaucrat bureaucrat3("Jack", 150);
    std::cout << "Bureaucrat " << bureaucrat3.getName() << " created with grade " << bureaucrat3.getGrade() << std::endl;
    try {
        bureaucrat3.decrementGrade();
        std::cout << "Bureaucrat " << bureaucrat3.getName() << " grade decremented to " << bureaucrat3.getGrade() << std::endl;

        bureaucrat3.incrementGrade();
        std::cout << "Bureaucrat " << bureaucrat3.getName() << " grade incremented to " << bureaucrat3.getGrade() << std::endl;

        // Try to decrement a bureaucrat with the minimum grade (should throw exception)
        bureaucrat3.decrementGrade();
        std::cout << "Bureaucrat " << bureaucrat3.getName() << " grade decremented to " << bureaucrat3.getGrade() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << std::endl;
    }

    return 0;
}
