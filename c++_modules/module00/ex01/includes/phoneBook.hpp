#include <iostream>
#include "../includes/contact.hpp"

class	PhoneBook
{
	private:
		Contact contact[8];
		int		index;
	public:
		PhoneBook();
		void addContact(Contact contact);
		Contact getContactValues(int indexValue);
};