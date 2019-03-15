/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:10:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:32:54 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Human::Human()
: brain("Bob", 200)
{
}

Human::~Human()
{
}

std::string Human::identify(void) const
{
	return this->brain.identify();
}

const Brain& Human::getBrain(void) const
{
	return brain;
}
