/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:24:55 by pbie              #+#    #+#             */
/*   Updated: 2019/03/12 18:19:03 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];

	public:
		Phonebook();
		int contacts_len;
		bool addContact();
		void printContacts();
};

#endif // PHONEBOOK_H
