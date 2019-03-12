/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phantastic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:50:12 by pbie              #+#    #+#             */
/*   Updated: 2019/03/12 19:09:45 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string buffer;

	std::cout << "Welcome to Phantastic Phonebook!" << std::endl;
	std::cout << "Please use commands EXIT, ADD, and SEARCH" << std::endl;

	while (buffer != "EXIT")
	{
		std::cout << "Enter a command: ";
		getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			if (phonebook.addContact())
				std::cout << "\nYour contact has been added!" << std::endl;
			else
				std::cout << "Sorry but the contact list is full!" << std::endl;
		}
		else if (buffer == "SEARCH")
		{
			std::cout << "you've selected SEARCH" << std::endl;
			if (phonebook.contacts_len < 1)
				std::cout << "Please add a contact before searching!" << std::endl;
			else {
				phonebook.printContacts();
				phonebook.search();
			}
		}
		else
		{
			std::cout << "Please use a valid command!" << std::endl;
		}
	}
	std::cout << "Thanks for using Phantastic Phonebook!" << std::endl;
	return 0;
}
