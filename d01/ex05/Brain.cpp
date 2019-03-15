/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:51:00 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:32:47 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>
#include <sstream>

Brain::Brain(std::string name, int iq)
{
	this->name = name;
	this->iq = iq;
}

Brain::~Brain()
{
}

std::string Brain::identify(void) const
{
	std::stringstream buffer;
	buffer << this;
	return buffer.str();
}
