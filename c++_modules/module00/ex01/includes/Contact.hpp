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
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		~Contact();
};