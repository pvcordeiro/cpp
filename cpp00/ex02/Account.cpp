#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:"
			<< _nbAccounts
			<< ";total:"
			<< _totalAmount 
			<< ";deposits:"
			<< _totalNbDeposits
			<< ";withdrawals:"
			<< _totalNbWithdrawals
			<< std::endl;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:"
			<< _accountIndex
			<< ";amount:"
			<< _amount
			<< ";created"
			<< std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:"
			<< _accountIndex
			<< ";amount:"
			<< _amount
			<< ";closed"
			<< std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:"
			<< _accountIndex
			<< ";p_amount:"
			<< _amount
			<< ";deposit:"
			<< deposit
			<< ";";
    
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    std::cout << "amount:"
			<< _amount
			<< ";nb_deposits:"
			<< _nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:"
			<< _accountIndex
			<< ";p_amount:"
			<< _amount
			<< ";";
    
    if (withdrawal > _amount)
        return (std::cout << "withdrawal:refused" << std::endl, false);
    
    std::cout << "withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    std::cout << "amount:"
			<< _amount
			<< ";nb_withdrawals:"
			<< _nbWithdrawals
			<< std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:"
			<< _accountIndex
			<< ";amount:"
			<< _amount 
            << ";deposits:"
			<< _nbDeposits
			<< ";withdrawals:"
			<< _nbWithdrawals
			<< std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm* timeinfo = std::localtime(&now);
    char buffer[256];
    
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
}
