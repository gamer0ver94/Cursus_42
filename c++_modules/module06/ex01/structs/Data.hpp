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
		std::cout << "First name: " << firstName << std::endl;
		std::cout << "Last name: " << lastName << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Address: " << address << std::endl;
		std::cout << "Description: " << description << std::endl;
	}
}	Data_t;