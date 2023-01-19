#include "../includes/phoneBook.hpp"
#include <stdlib.h>
#include "../includes/colors.hpp"
#include <sstream>

void	addContact(PhoneBook *phoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	system("clear");
	std::cout << BLUE << "[ADD]" << WHITE << std::endl;
	std::cout << YELLOW << "Please Enter Your First Name :" << WHITE << std::endl;
	std::cin >> firstName;
	std::cout << YELLOW << "Please Enter Your Last Name :" << WHITE  << std::endl;
	std::cin >> lastName;
	std::cout << YELLOW << "Please Enter Your Nickname :" << WHITE  << std::endl;
	std::cin >> nickName;
	std::cout << YELLOW << "Please Enter Your Phone Number :" << WHITE  << std::endl;
	std::cin >> phoneNumber;
	std::cout << YELLOW << "Please Enter Your Darkest Secret :" << WHITE  << std::endl;
	std::cin >> darkestSecret;
	system("clear");
	Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phoneBook->addContact(contact);
}

std::string	trunctMoreThanTen(std::string string){
	bool	isMoreThenTen;
	std::string newTrunced;

	isMoreThenTen = string.std::string::length() > 9;
	if (!isMoreThenTen)
		return (string);
	newTrunced = string.std::string::substr(0, 9);
	newTrunced.std::string::append(".");
	return (newTrunced);
}

std::string	trunctLessThanTen(std::string string){
	bool	isLessThenTen;
	std::string newTrunced;

	newTrunced = string;
	isLessThenTen = string.std::string::length() < 10;
	if (!isLessThenTen)
		return (string);
	while (newTrunced.std::string::length() < 10){
		newTrunced.std::string::append(" ");
		isLessThenTen = string.std::string::length() < 9;
	}
	return (newTrunced);
}

void	printContactByIndex(Contact contact)
{
	if (contact.getFirstName().std::string::length() == 0)
	{
		std::cout << RED << "THIS CONTACT DOESN'T EXIT" << "\033[0;37m" << WHITE <<std::endl;
		return ;
	}
	system("clear");
	std::cout << GREEN << "CONTACT INFO" << WHITE <<std::endl;
	std::cout << BLUE << "[FIRST NAME] => " << contact.getFirstName() << WHITE << std::endl;
	std::cout << BLUE << "[LAST NAME]=> " << contact.getLastName() << WHITE << std::endl;
	std::cout << BLUE << "[NICKNAME] => " << contact.getNickName() << WHITE << std::endl;
	std::cout << BLUE << "[PHONE NUMBER] => " << contact.getPhoneNumber() << WHITE << std::endl;
	std::cout << BLUE << "[DARKEST SECRET] => " << contact.getNickName() << WHITE << std::endl;
}

void searchContact(PhoneBook *phoneBook){
	std::string index;
	char *end;

	end = NULL;
	std::cout << "Please enter the contact index or type '0' to return:" << std::endl;
	while (!strtod(index.c_str(), &end) || strtod(index.c_str(), &end) > 8){
		std::cin >> index;
		if (!strtod(index.c_str(), &end)){
			system("clear");
			return;
		}
		strtod(index.c_str(), &end) > 8 && std::cout << RED << \
			"Out range number detected, please enter a valid contact index (1 ~ 8)" << WHITE << std::endl;
		!strtod(index.c_str(), &end) && std::cout << RED << \
			"Caracter detected, please enter a valid contact index (1 ~ 8)" << WHITE << std::endl;
	}
	printContactByIndex(phoneBook->getContactValues(strtod(index.c_str(), &end) - 1));
}

void	displayContacts(PhoneBook phoneBook){
	int i;

	i = 0;
	system("clear");
	std::cout << CYAN;
	std::cout << "INDEX    " << "|" << "FIRST NAME" << "|" << "LAST NAME " << "|" << "NICKNAME  " << "|" << WHITE << std::endl;
	while (i < 8 && phoneBook.getContactValues(i).getFirstName().std::string::length()) {
		std::cout << YELLOW << i + 1 << "        " << "|";
		std::cout << trunctLessThanTen(trunctMoreThanTen(phoneBook.getContactValues(i).getFirstName())) << "|";
		std::cout << trunctLessThanTen(trunctMoreThanTen(phoneBook.getContactValues(i).getLastName())) << "|";
		std::cout << trunctLessThanTen(trunctMoreThanTen(phoneBook.getContactValues(i).getNickName())) << "|" << WHITE << std::endl;
		i++;
	}
}

int main(void)
{
	system("clear");
	std::string 	option;
	PhoneBook		phoneBook;

	while(option != "EXIT"){
		std::cout << "Please enter one of the following options :" << std::endl;
		std::cout << "\033[0;34m" << "[ADD] [SEARCH] [EXIT]" << "\033[0;37m" << std::endl;
		std::cin >> option;
		if (option == "ADD"){
			addContact(&phoneBook);
		}
		else if (option == "SEARCH"){
			displayContacts(phoneBook);
			searchContact(&phoneBook);
		}
	}
	return (0);
}