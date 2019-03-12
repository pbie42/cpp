/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:00:30 by pbie              #+#    #+#             */
/*   Updated: 2019/03/12 18:36:54 by pbie             ###   ########.fr       */
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
	contact->setFirstName(getInfo("First Name: "));
	contact->setLastName(getInfo("Last Name: "));
	contact->setNickname(getInfo("Nickname: "));
	contact->setPostalAddress(getInfo("Postal Address: "));
	contact->setEmailAddress(getInfo("Email Address: "));
	contact->setPhoneNumber(getInfo("Phone Number: "));
	contact->setBirthDate(getInfo("Birth Date: "));
	contact->setFavoriteMeal(getInfo("Favorite Meal: "));
	contact->setUnderwearColor(getInfo("Underwear Color: "));
	contact->setDarkestSecret(getInfo("Darkest Secret: "));
	contacts_len++;
	return true;
}

void Phonebook::printContacts()
{
	int x = 0;
	int len = 0;

	while(x < contacts_len)
	{
		std::cout << "         " << x << "|";
		len = contacts[x].getFirstName().length();
		std::cout << contacts[x].getFirstName();
		x++;
	}
}

std::string getInfo(std::string field)
{
	std::string buffer;

	std::cout << field;
	getline(std::cin, buffer);
	return buffer;
}

void printSpaces(int spaces)
{
	int x = 0;
	while(x < spaces)
	{
		std::cout << " ";
	}
}
