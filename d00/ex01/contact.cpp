/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:01:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/12 18:14:12 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "contact.hpp"

Contact::Contact() {}

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
