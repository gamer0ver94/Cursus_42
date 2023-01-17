#include <iostream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		Contact(std::string firstName, 	std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
		void getContactValues();
		~Contact();
};