/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:58:42 by pbie              #+#    #+#             */
/*   Updated: 2019/03/13 16:47:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;
int Account::_totalAmount;
int Account::_nbAccounts;

Account::Account(int inital_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = inital_deposit;
	this->_nbDeposits = 1;
	this->_nbWithdrawals = 0;

	Account::_totalNbDeposits++;
	Account::_totalAmount += inital_deposit;
}

Account::~Account()
{
	std::cout << "Deleting Account" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	std::cout << "\nAccounts Infos" << std::endl;
	std::cout << "NbAccounts:    " << getNbAccounts() << std::endl;
	std::cout << "NbDeposits:    " << getNbDeposits() << std::endl;
	std::cout << "NbWithdrawals: " << getNbWithdrawals() << std::endl;
	std::cout << "TotalAmount:   " << getTotalAmount() << std::endl;
	std::cout << "" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0) {
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		return true;
	}
	return false;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	std::cout << "\nAccount Info" << std::endl;
	std::cout << "Account Index: " << _accountIndex << std::endl;
	std::cout << "Amount       : " << _amount << std::endl;
	std::cout << "NbDeposits   : " << _nbDeposits << std::endl;
	std::cout << "NbWithdrawals: " << _nbWithdrawals << std::endl;
	std::cout << "" << std::endl;
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
