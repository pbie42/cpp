/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:10:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:19:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Human::Human()
: brain("Bob", 200)
{
	std::cout << "human created" << std::endl;
	std::cout << this->brain.identify() << std::endl;
}

Human::~Human()
{
	std::cout << "human destroyed" << std::endl;
}

std::string Human::identify(void) const
{
	std::cout << this->brain.identify() << std::endl;
	return this->brain.identify();
}

const Brain& Human::getBrain(void) const
{
	std::cout << this->brain.identify() << std::endl;
	// const Brain& brainRef = this->brain;
	return brain;
}
