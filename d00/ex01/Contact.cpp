/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:01:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 10:49:01 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

Contact::Contact() {}

void Contact::printInfo()
{
	std::cout << "" << std::endl;
	std::cout << "First Name:      " << Contact::getFirstName() << std::endl;
	std::cout << "Last Name:       " << Contact::getLastName() << std::endl;
	std::cout << "Nickname:        " << Contact::getNickname() << std::endl;
	std::cout << "Postal Address:  " << Contact::getPostalAddress() << std::endl;
	std::cout << "Email Address:   " << Contact::getEmailAddress() << std::endl;
	std::cout << "Phone Number:    " << Contact::getPhoneNumber() << std::endl;
	std::cout << "Birth Date:      " << Contact::getBirthDate() << std::endl;
	std::cout << "Favorite Meal:   " << Contact::getFavoriteMeal() << std::endl;
	std::cout << "Underwear Color: " << Contact::getUnderwearColor() << std::endl;
	std::cout << "Darkest Secret:  " << Contact::getDarkestSecret() << std::endl;
	std::cout << "" << std::endl;
}

void Contact::setInfo()
{
	std::cout << "" << std::endl;
	Contact::setFirstName(getInfo("First Name: "));
	Contact::setLastName(getInfo("Last Name: "));
	Contact::setNickname(getInfo("Nickname: "));
	Contact::setPostalAddress(getInfo("Postal Address: "));
	Contact::setEmailAddress(getInfo("Email Address: "));
	Contact::setPhoneNumber(getInfo("Phone Number: "));
	Contact::setBirthDate(getInfo("Birth Date: "));
	Contact::setFavoriteMeal(getInfo("Favorite Meal: "));
	Contact::setUnderwearColor(getInfo("Underwear Color: "));
	Contact::setDarkestSecret(getInfo("Darkest Secret: "));
}

void Contact::setFirstName(std::string str)
{
	first_name = str;
};
void Contact::setLastName(std::string str)
{
	last_name = str;
};
void Contact::setNickname(std::string str)
{
	nick_name = str;
};
void Contact::setPostalAddress(std::string str)
{
	postal_address = str;
};
void Contact::setEmailAddress(std::string str)
{
	email_address = str;
};
void Contact::setPhoneNumber(std::string str)
{
	phone_number = str;
};
void Contact::setBirthDate(std::string str)
{
	birth_date = str;
};
void Contact::setFavoriteMeal(std::string str)
{
	favorite_meal = str;
};
void Contact::setUnderwearColor(std::string str)
{
	underwear_color = str;
};
void Contact::setDarkestSecret(std::string str)
{
	darkest_secret = str;
};
std::string Contact::getFirstName()
{
	return first_name;
};
std::string Contact::getLastName()
{
	return last_name;
};
std::string Contact::getNickname()
{
	return nick_name;
};
std::string Contact::getPostalAddress()
{
	return postal_address;
};
std::string Contact::getEmailAddress()
{
	return email_address;
};
std::string Contact::getPhoneNumber()
{
	return phone_number;
};
std::string Contact::getBirthDate()
{
	return birth_date;
};
std::string Contact::getFavoriteMeal()
{
	return favorite_meal;
};
std::string Contact::getUnderwearColor()
{
	return underwear_color;
};
std::string Contact::getDarkestSecret()
{
	return darkest_secret;
};
