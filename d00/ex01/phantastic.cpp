/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phantastic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:50:12 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 11:08:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

void handleAdd(Phonebook *phonebook)
{
	if (phonebook->addContact())
		std::cout << "\nYour contact has been added!\n" << std::endl;
	else
		std::cout << "Sorry but the contact list is full!" << std::endl;
}

void handleSearch(Phonebook *phonebook)
{
	if (phonebook->contacts_len < 1)
		std::cout << "\nPlease add a contact before searching!\n" << std::endl;
	else
	{
		phonebook->printContacts();
		phonebook->search();
	}
}

int main()
{
	Phonebook phonebook;
	std::string buffer;

	std::cout << "Welcome to Phantastic Phonebook!" << std::endl;
	std::cout << "Please use the commands EXIT, ADD, and SEARCH" << std::endl;

	while (buffer != "EXIT")
	{
		std::cout << "Enter a command: ";
		getline(std::cin, buffer);
		if (buffer == "ADD")
			handleAdd(&phonebook);
		else if (buffer == "SEARCH")
			handleSearch(&phonebook);
		else if (buffer == "EXIT")
			;
		else
			std::cout << "\nPlease use a valid command!\n" << std::endl;
	}
	std::cout << "\nThanks for using Phantastic Phonebook!\n" << std::endl;
	return 0;
}
