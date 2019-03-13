/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:00:30 by pbie              #+#    #+#             */
/*   Updated: 2019/03/13 12:02:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

std::string getInfo(std::string field);
void printSpaces(int spaces);

Phonebook::Phonebook()
{
	contacts_len = 0;
}

bool Phonebook::addContact()
{
	Contact *contact;

	if (contacts_len >= 8)
		return false;
	contact = &(contacts[contacts_len]);
	contact->setInfo();
	contacts_len++;
	return true;
}

void Phonebook::search()
{
	bool valid = false;
	int index;

	while(!valid){
		std::cout << "Please enter the number of the contact you would like information for: ";
		std::cin >> index;
		if (index >= 0 && index <= contacts_len) valid = true;
		std::cin.ignore();
	}
	contacts[index].printInfo();
}

void Phonebook::printContacts()
{
	int x = 0;
	int len = 0;
	std::string str;

	std::cout << "" << std::endl;
	while(x < contacts_len)
	{
		printSpaces(9);
		std::cout << x << "|";
		handleFormat(contacts[x].getFirstName());
		handleFormat(contacts[x].getLastName());
		handleFormat(contacts[x].getNickname());
		x++;
		std::cout << "" << std::endl;
	}
	std::cout << "" << std::endl;
}

void handleFormat(std::string string)
{
	int len = 0;
	std::string str;

	len = string.length();
	if (len > 10) str = string.substr(0, 9) + ".";
	else
	{
		printSpaces(10 - len);
		str = string;
	}
	std::cout << str << "|";
}

void printSpaces(int spaces)
{
	int x = 0;
	while(x < spaces)
	{
		std::cout << " ";
		x++;
	}
}
