/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casualty.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:43:50 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 21:50:20 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Casualty.hpp"

Casualty::Casualty(/* args */) : Victim("Normal")
{
	std::cout << "Glub glub." << std::endl;
}

Casualty::Casualty(std::string name) : Victim(name)
{
	std::cout << "Glub glub." << std::endl;
}

Casualty::Casualty(const Casualty &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Casualty::~Casualty()
{
	std::cout << "Ahhhhhhhhhhhhh......" << std::endl;
}

Casualty & Casualty::operator=(Casualty const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setName(rhs.getName());
	return *this;
}

void Casualty::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a rainbow unicorn !" << std::endl;
}
