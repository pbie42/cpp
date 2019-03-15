/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:51:00 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:15:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>
#include <sstream>

Brain::Brain(std::string name, int iq)
{
	std::cout << "brain created" << std::endl;
	this->name = name;
	this->iq = iq;
}

Brain::~Brain()
{
	std::cout << "brain destroyed" << std::endl;
}

std::string Brain::identify(void) const
{
	std::stringstream buffer;
	std::cout << this << std::endl;
	buffer << this;
	return buffer.str();
}
