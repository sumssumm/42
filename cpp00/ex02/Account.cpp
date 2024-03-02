#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits--;
	_totalNbWithdrawals--;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout	<< " accounts:" << getNbAccounts() \
				<< ";total:" << getTotalAmount() \
				<< ";deposits:" << getNbDeposits() \
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << _amount \
				<< ";deposit:";
	if (deposit > 0)
	{
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
		std::cout	<< deposit \
					<< ";amount:" << _amount \
					<< ";nb_deposits:" << _nbDeposits << std::endl;
	}
	else
		std::cout << "refused" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << _amount \
				<< ";withdrawal:";
	if (withdrawal > 0 && withdrawal <= checkAmount())
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout	<< withdrawal \
					<< ";amount:" << _amount \
					<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	else
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	return true;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	tm = time(NULL);
	struct tm *time = localtime(&tm);
	char	buffer[18];

	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", time);
	std::cout << buffer;
}
