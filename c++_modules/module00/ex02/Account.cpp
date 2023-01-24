#include "Account.hpp"
#include <iostream>
#include<ctime>
#include <chrono>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void){
	this->_displayTimestamp();
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
}

Account::Account(int initial_deposit){
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void){
	this->_displayTimestamp();
	this->_nbAccounts--;
		std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit( int deposit ){
	this->_displayTimestamp();
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits;" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal ){
	this->_displayTimestamp();
	if (this->_amount - withdrawal < 0){
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawal:" << this->_nbWithdrawals + 1 << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount( void ) const{
	return (this->_amount);
}

void Account::displayStatus( void ) const{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ":deposits:" << getNbDeposits() << ":withdrawals:" << getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void ){
	std::time_t currentTime;
	tm *timeStruct;
	char date[9];

	currentTime = time(0);
	timeStruct = localtime(&currentTime);
	strftime(date, 9,"%Y%m%d", timeStruct);
	std::cout << date << " ";
}