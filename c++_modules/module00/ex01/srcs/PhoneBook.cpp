#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	std::cout << "\033[0;32m" << "Phone Book created with success" << std::endl;
	std::cout << "\033[0;37m";
}

void	PhoneBook::addContact(Contact contact)
{
	PhoneBook::contact[index] = contact;
	this->index = index > 6 ? 0 : index + 1;
}

Contact PhoneBook::getContactValues(int indexValue)
{
	return(contact[indexValue]);
}