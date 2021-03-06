/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:24:55 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 10:49:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];

	public:
		Phonebook();
		int contacts_len;
		bool addContact();
		void printContacts();
		void search();
};

#endif // PHONEBOOK_H
