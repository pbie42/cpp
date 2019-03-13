/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:00:30 by pbie              #+#    #+#             */
/*   Updated: 2019/03/13 14:23:20 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

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
		if (index >= 1 && index <= contacts_len) valid = true;
		else std::cout << "\nPlease enter a valid number\n" << std::endl;
		std::cin.sync();
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	contacts[index - 1].printInfo();
}

void Phonebook::printContacts()
{
	int x = 0;

	std::cout << "" << std::endl;
	while(x < contacts_len)
	{
		printSpaces(9);
		std::cout << x + 1 << "|";
		handleFormat(contacts[x].getFirstName());
		handleFormat(contacts[x].getLastName());
		handleFormat(contacts[x].getNickname());
		x++;
		std::cout << "" << std::endl;
	}
	std::cout << "" << std::endl;
}
