#include <iostream>
#include "../includes/contact.hpp"

class	PhoneBook
{
	private:
		Contact contact[8];
	public:
		PhoneBook();
		void addContact(Contact contact);
		void getContactValues(Contact contact);
};