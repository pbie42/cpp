/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fatality.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:43:50 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 22:15:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fatality.hpp"

Fatality::Fatality(/* args */) : Victim("Normal")
{
	std::cout << "Bloop bloop." << std::endl;
}

Fatality::Fatality(std::string name) : Victim(name)
{
	std::cout << "Bloop bloop." << std::endl;
}

Fatality::Fatality(const Fatality &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fatality::~Fatality()
{
	std::cout << "Noooooooo......" << std::endl;
}

Fatality & Fatality::operator=(Fatality const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setName(rhs.getName());
	return *this;
}

void Fatality::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a mint mantaray !" << std::endl;
}
