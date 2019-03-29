/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:48:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 17:49:54 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Cure(/* args */);
		Cure(Cure const &f);
		virtual ~Cure();
		Cure & operator=(Cure const &rhs);
};

Cure::Cure(/* args */)
{
}

Cure::Cure(const Cure &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Cure::~Cure()
{
}

Cure & Cure::operator=(Cure const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

#endif // CURE_H
