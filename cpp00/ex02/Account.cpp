/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:14:11 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:14:13 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// declare varaible
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _amount += initial_deposit;
    _totalAmount += initial_deposit;
    _accountIndex = _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";created" << std::endl;
}

Account::~Account ( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";closed" << std::endl;
}

// public
int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    std::cout << ";deposits:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";nb_deposits:" << ++_nbDeposits << std::endl;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    if (withdrawal > checkAmount())
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
    _totalNbWithdrawals++;
    return (true);
}

int Account::checkAmount( void ) const
{
    return (_amount);
}

void Account::displayStatus( void ) const
{
     _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;   
}

// private
void Account::_displayTimestamp( void )
{
    time_t now = std::time(0);
    tm *ts = localtime(&now);

    std::cout << "[" << ts->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << ts->tm_mon + 1;
    std::cout << std::setw(2) << ts->tm_mday << "_";
    std::cout << std::setw(2) << ts->tm_hour;
    std::cout << std::setw(2) << ts->tm_min;
    std::cout << std::setw(2) << ts->tm_sec << "] ";
}
