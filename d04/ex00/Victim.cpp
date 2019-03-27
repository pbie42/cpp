/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:51:47 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 15:26:12 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(/* args */) :
name("Default")
{
}

Victim::Victim(std::string name) :
name(name)
{
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::Victim(const Victim &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}

void Victim::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

Victim & Victim::operator=(Victim const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setName(rhs.getName());
	return *this;
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs)
{
	std::stringstream ss;

	ss << "I'm " << rhs.getName() << " and I like otters !\n";
	o << ss.str();
	return o;
}

std::string Victim::getName() const
{
	return this->name;
}

void Victim::setName(std::string name)
{
	this->name = name;
}
