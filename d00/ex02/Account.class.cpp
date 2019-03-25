/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:58:42 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 12:04:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <iomanip>

std::string date()
{
	time_t seconds = time (NULL);

	struct tm * timeinfo = localtime (&seconds);

	std::ostringstream oss;
	oss << "[" << (timeinfo->tm_year + 1900) << ""
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1) << ""
	<< std::setw(2) << std::setfill('0') << timeinfo->tm_mday << "_"
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_hour) << ""
	<< std::setw(2) << std::setfill('0') << timeinfo->tm_min << ""
	<< std::setw(2) << std::setfill('0') << timeinfo->tm_sec << "]";

	std::string data = oss.str();

	return data;
}

int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;
int Account::_totalAmount;
int Account::_nbAccounts;

Account::Account(int inital_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = inital_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// Account::_totalNbDeposits++;
	Account::_totalAmount += inital_deposit;
	std::cout << date() << " " << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	std::cout << date() << " " << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	std::cout << date() << " " << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	std::cout << date() << " " << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
	std::cout << ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

}

bool Account::makeWithdrawal(int withdrawal)
{
	std::cout << date() << " " << "index:" << _accountIndex
	<< ";p_amount:" << _amount;
	if (_amount - withdrawal >= 0) {
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return true;
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return false;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	std::cout << date() << " " << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}
