/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:50:03 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 15:02:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
#define OFFICEBLOCK_H

#include <iostream>
#include <string>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
	private:
		OfficeBlock(OfficeBlock const &f);
		OfficeBlock & operator=(OfficeBlock const &rhs);
		Intern *_intern;
		Bureaucrat *_signer;
		Bureaucrat *_executor;
	protected:
		/* data */
	public:
		OfficeBlock(/* args */);
		virtual ~OfficeBlock();
		void setIntern(Intern *);
		void setSigner(Bureaucrat *);
		void setExecutor(Bureaucrat *);
};

OfficeBlock::OfficeBlock(/* args */)
{
}

OfficeBlock::OfficeBlock(const OfficeBlock &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

OfficeBlock::~OfficeBlock()
{
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void OfficeBlock::setIntern(Intern *i)
{
	this->_intern = i;
}

void OfficeBlock::setSigner(Bureaucrat *s)
{
	this->_signer = s;
}

void OfficeBlock::setExecutor(Bureaucrat *e)
{
	this->_executor = e;
}

#endif // OFFICEBLOCK_H
