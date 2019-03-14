/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:51:37 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 13:45:49 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony(std::string n, std::string c, int h)
{
	this->name = n;
	this->color = c;
	this->height = h;
	std::cout << "The pony " << this->name << " has descended upon the earth in " << this->color << " brilliance at " << this->height << "cm" << std::endl;
}

Pony::~Pony()
{
	std::cout << "The pony " << this->name << " is heading to the great glue factory in the sky" << std::endl;
}

void Pony::neigh(void)
{
	std::cout << this->name << " neighs with the force of a thousand suns!" << std::endl;
}
