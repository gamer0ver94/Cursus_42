#include "../includes/contact.hpp"

Contact::Contact()
{

}

Contact::Contact(std::string firstName, 	std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	std::cout << "Contact created..." << std::endl;
}
Contact::~Contact()
{
	std::cout << "Contact destroyed..." << std::endl;
}

void	getContactValues()
{
	this.first
	// std::cout << "first name" << firstName << std::endl;
	// std::cout << "last name" << lastName << std::endl;
	// std::cout << "nick name" << nickName << std::endl;
	// std::cout << "phone number" << phoneNumber << std::endl;
	// std::cout << "secret" << darkestSecret<< std::endl;
}