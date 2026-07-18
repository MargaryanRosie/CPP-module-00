// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;    //dynamic array    Account::t means Account
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	//std::pair<int, std::string> p;

	//p.first = 42;
	//p.second = "hello";

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };      //Initial balances of the accounts
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );      //creating the vector of the accounts
	//so the constructor is called each time the object is created
	//function that takes the first pointer to the amounts
	//amounts + amounts_size means move the pointer forward by 8 elements
	//and it returns a dynamic array of Account objects
	accounts_t::iterator	acc_begin	= accounts.begin();
	//accounts_t is a vector, and iterator is a special type inside the vector
	//iterator is a pointer-like object that can move through the vector
	//so now acc_begin is an iterator type which is used to walk through a vector of accounts
	//accounts.begin() returns a pointer to the first element of the vector
	accounts_t::iterator	acc_end		= accounts.end();
	//returns a pointer to the last element of the vector

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );       //displayStatus is a member function, so it needs an object, so mem_fun_ref
	                                                                                       //converts it to something that for_each can use

	for ( acc_int_t it( acc_begin, dep_begin );          //initialize the pair with initial values, it is a variable, first is acc_begin and second is dep_begin
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {                 //move both iterators forward

		(*(it.first)).makeDeposit( *(it.second) );         //*(it.first) is an Account object, so we call makeDeposit function on it with the object that contains deposit value
	}

	//std::for_each(begin, end, function);      this means run this function on every element between begin and end

	Account::displayAccountsInfos();         //a static member function, no object needed
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// Account::displayAccountsInfos();
	// std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
