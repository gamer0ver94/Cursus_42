#include "../includes/phoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Phone Book created with success" << std::endl;
}

void	PhoneBook::addContact(Contact contact)
{
	PhoneBook::contact[0] = contact;
}

void getContactValues(Contact contact)
{
	contact.getContactValues();
}