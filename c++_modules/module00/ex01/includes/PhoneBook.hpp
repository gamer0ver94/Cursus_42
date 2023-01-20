#include <iostream>
#include "../includes/Contact.hpp"

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