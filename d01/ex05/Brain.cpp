/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:51:00 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 11:59:47 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <sstream>

Brain::Brain()
{
}

Brain::~Brain()
{
}

std::string Brain::identify(void)
{
	std::ostringstream buffer;

	buffer << this;
	return buffer.str();
}
