/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:20:20 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 18:06:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
	private:
		/* data */
		AMateria(/* args */);
	protected:
		/* data */
		unsigned int xp_;
		std::string type;
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &f);
		virtual ~AMateria();
		AMateria & operator=(AMateria const &rhs);
		std::string const & getType() const;
		unsigned int getXP() const;
		void increaseXP();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

AMateria::AMateria(/* args */)
{
}

AMateria::AMateria(std::string const & type) :
type(type),
xp_(0)
{
}

AMateria::AMateria(const AMateria &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter& target)
{
	if (this->type.compare("ice") == 0)
		std::cout << "* shoots an ice bolt at" << target.getName() << " *" << std::endl;
	if (this->type.compare("cure") == 0)
		std::cout << "* heals" << target.getName() << "'s wounds *" << std::endl;
}

AMateria & AMateria::operator=(AMateria const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		this->xp_ = rhs.getXP();
	}
	return *this;
}

void AMateria::increaseXP()
{
	this->xp_ += 10;
}

unsigned int AMateria::getXP() const
{
	return this->xp_;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

#endif // AMATERIA_H
