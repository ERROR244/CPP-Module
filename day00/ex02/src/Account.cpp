#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

int     Account::checkAmount( void ) const
{
    return this->_amount;
}

void Account::_displayTimestamp()
{
    std::time_t result;

    std::time(&result);
    std::cout << std::setfill('0') << "[" << std::localtime(&result)->tm_year + 1900
                << std::setw(2) << std::localtime(&result)->tm_mon + 1
                <<  std::setw(2) << std::localtime(&result)->tm_mday
                <<  "_"
                <<  std::setw(2) << std::localtime(&result)->tm_hour
                <<  std::setw(2) << std::localtime(&result)->tm_min
                <<  std::setw(2) << std::localtime(&result)->tm_sec
                << "] ";
}

void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    // static
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    // none static
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account( void ) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {}

Account::~Account( void )
{
    Account::_nbAccounts--;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << std::flush;
    this->_amount += deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal )
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << std::flush;
    if (withdrawal <= checkAmount())
    {
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbDeposits << std::endl;
        return true;
    }
    std::cout << "refused" << std::endl;
    return false;
}

void    Account::displayStatus( void ) const
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
