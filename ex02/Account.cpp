#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//Constructor runs automatocally each time the object is cretaed
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

//Creating the helper function to display the timestamp

void    Account::_displayTimestamp(void)
{
    std::time_t rawtime;        //seconds since 1970, but its not human readable
    std::tm* timeinfo;  //std::tm* is the type of the variable(it is declared in the standard library which is in the namespace std)
    char    buffer[20];

    std::time(&rawtime);
    //Called as std::time(nullptr), it returns the current time as a time_t.

    //struct tm* localtime( const time_t* timer );
    //this cconverts raw time_t into a struct with seperate fields like
    //tm_year, tm_mon, tm_hour
    //it returns a pointer to the tm struct

    timeinfo = std::localtime(&rawtime);
    std::strftime( buffer, sizeof( buffer ), "%Y%m%d_%H%M%S", timeinfo );
	std::cout << "[" << buffer << "] "; 
}

Account::~Account( void ) {
 
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			   << ";amount:" << _amount
			   << ";closed" << std::endl;
}


//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
        << ";withdrawals:" << _totalNbWithdrawals
        << std::endl;
}


void    Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    int p_amount = _amount;
    _amount += deposit; 
    _nbDeposits++;
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << p_amount
                << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits
                << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

// int main()
// {
//     Account account(42);

//     return 0;
// }