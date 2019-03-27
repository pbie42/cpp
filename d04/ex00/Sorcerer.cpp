/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:51:06 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 15:24:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(/* args */)
{
}

Sorcerer::Sorcerer(std::string name, std::string title) :
name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", is dead. "
	<< "Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const & vic) const
{
	vic.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(Sorcerer const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setName(rhs.getName());
	this->setTitle(rhs.getTitle());
	return *this;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs)
{
	std::stringstream ss;

	ss << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !\n";
	o << ss.str();
	return o;
}

std::string Sorcerer::getName() const
{
	return this->name;
}

void Sorcerer::setName(std::string name)
{
	this->name = name;
}

std::string Sorcerer::getTitle() const
{
	return this->title;
}

void Sorcerer::setTitle(std::string title)
{
	this->title = title;
}
