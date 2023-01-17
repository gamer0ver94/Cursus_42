#include "../includes/phoneBook.hpp"

void	addContact(PhoneBook *phoneBook)
{
	(void)phoneBook;
	Contact contact("a", "a", "a", "a", "a");
	phoneBook->addContact(contact);
	
}

int main(void)
{
	std::string 	option;
	PhoneBook		phoneBook;
	unsigned int	i;

	i = 5;
	while(option != "ADD" && option != "SEARCH" && option != "EXIT")
	{
		system("clear");
		std::cout << "Please Enter one of the following options -> ADD, SEARCH, EXIT" << std::endl;
		std::cin >> option;
	}
	if (option == "EXIT")
	{
		exit(0);
	}
	else if (option == "ADD")
	{
		std::cout << "Please Enter by order << FIST NAME << LAST NAME << PHONE NUMBER << DARKEST SECRET" << std::endl;
		addContact(&phoneBook);
	}
	else
	{
		std::cout << "search selected" << std::endl;
	}
	return (0);
}