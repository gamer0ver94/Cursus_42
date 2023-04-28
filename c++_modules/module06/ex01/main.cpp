#include "classes/Serializer.hpp"
#include <iostream>
#include <fstream>

int main(void){
	uintptr_t ptr;
	std::string fileName = "data.bin";
	std::ifstream fileIn(fileName, std::ios::binary);
	Data *deserializedData;
	if (fileIn.good()){
		Data newData;
		std::cout << "File " << fileName << " exists" << std::endl;
		std::cout << "Reading from " << fileName << std::endl;
		fileIn.read(reinterpret_cast<char*>(&newData), sizeof(Data));
		std::cout << "Deserializing success." << std::endl;
		newData.getData();
		fileIn.close();
		ptr = Serializer::serialize(&newData);
		deserializedData = Serializer::deserialize(ptr);
		if ((deserializedData) == &newData){
			std::cout << "Pointer is the same" << std::endl;
			std::cout << deserializedData << std::endl << &newData << std::endl;
		}
		else{
			std::cout << "Pointer is not the same" << std::endl;
		}
	}
	else{
		fileIn.close();
		std::string firstName;
		std::string lastName;
		std::string age;
		std::string address;
		std::string description;
		std::getline(std::cin, firstName);
		std::getline(std::cin, lastName);
		std::getline(std::cin, age);
		std::getline(std::cin, address);
		std::getline(std::cin, description);
		Data data(firstName, lastName, std::stoi(age), address, description);
		ptr = Serializer::serialize(&data);
		std::cout << "Serializing success." << std::endl;
		std::cout << "Opening " << fileName << std::endl;
		std::ofstream fileOut(fileName, std::ios::binary);
		std::cout << "Writing into " << fileName << std::endl;
		fileOut.write(reinterpret_cast<char*>(&data), sizeof(data));
		std::cout << "Writing success. " << std::endl;
		fileOut.close();
		ptr = Serializer::serialize(&data);
		deserializedData = Serializer::deserialize(ptr);
		if ((deserializedData) == &data){
			std::cout << "Pointer is the same" << std::endl;
			std::cout << deserializedData << std::endl << &data << std::endl;
		}
		else{
			std::cout << "Pointer is not the same" << std::endl;
		}
	}
}