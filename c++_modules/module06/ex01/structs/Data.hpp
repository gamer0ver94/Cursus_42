#include <iostream>

typedef struct Data{
	std::string firstName;
	std::string lastName;
	int age;
	std::string address;
	std::string description;
	
	Data() : age(0){};
	Data(std::string firstName, std::string lastName, int age, std::string address, std::string description) : 
	firstName(firstName), lastName(lastName), age(age), address(address), description(description){}
	void getData(){
		std::cout << "\033[34m" << "First name: " << "\033[37m" << firstName << std::endl;
		std::cout << "\033[34m" << "Last name: " << "\033[37m" << lastName << std::endl;
		std::cout << "\033[34m" << "Age: " << "\033[37m" << age << std::endl;
		std::cout << "\033[34m" << "Address: " << "\033[37m" << address << std::endl;
		std::cout << "\033[34m" << "Description: " << "\033[37m" << description << std::endl;
	}
}	Data_t;