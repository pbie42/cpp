/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:30:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/13 14:18:36 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birth_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
	public:
		Contact();
		void printInfo();
		void setInfo();
		void setFirstName(std::string str);
		std::string getFirstName();
		void setLastName(std::string str);
		std::string getLastName();
		void setNickname(std::string str);
		std::string getNickname();
		void setPostalAddress(std::string str);
		std::string getPostalAddress();
		void setEmailAddress(std::string str);
		std::string getEmailAddress();
		void setPhoneNumber(std::string str);
		std::string getPhoneNumber();
		void setBirthDate(std::string str);
		std::string getBirthDate();
		void setFavoriteMeal(std::string str);
		std::string getFavoriteMeal();
		void setUnderwearColor(std::string str);
		std::string getUnderwearColor();
		void setDarkestSecret(std::string str);
		std::string getDarkestSecret();

};

#endif // CONTACT_H
