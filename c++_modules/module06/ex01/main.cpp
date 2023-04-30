#include "classes/Serializer.hpp"
#include <iostream>
#include <fstream>

int main(void){
	std::string firstName;
	std::string lastName;
	std::string age;
	std::string address;
	std::string description;
	uintptr_t tmp = 0;
	std::cout << "First name: " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "age: " << std::endl;
	std::getline(std::cin, age);
	std::cout << "Address: " << std::endl;
	std::getline(std::cin, address);
	std::cout << "Description: " << std::endl;
	std::getline(std::cin, description);
	system("clear");
	try{
		Data* data = new Data(firstName, lastName, std::stoi(age), address, description);
		if (data){
		std::cout << "\033[32m" << "Data object created." << "\033[37m" << std::endl;
		data->getData();
		}
		else{
			std::cout << "\033[0m" << "Data object failed to be created." << "\033[37m" << std::endl;
		}
		tmp = Serializer::serialize(data);
		if (tmp){
			std::cout << "\033[32m" << "Serialization sucessfull" << "\033[37m" <<std::endl;
		}
		else{
			std::cout << "\033[0m" << "Serialization unsuccefull" << "\033[37m" << std::endl;
		}
		Data *newData = Serializer::deserialize(tmp);
		if (newData){
			std::cout << "\033[32m" << "Deserialization sucessfull" << "\033[37m" << std::endl;
		}
		else{
			std::cout << "\033[0m" << "Deserialization unsuccefull" << "\033[37m" << std::endl;
		}
		newData->getData();
		std::cout << "data address " << data << std::endl << "new data address " << newData << std::endl;
		delete data;
	}
	catch(std::exception&e){
		std::cout << e.what() << " could not convert a string please write age as a int." << std::endl;
	}
}