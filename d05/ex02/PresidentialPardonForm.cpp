/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:58:40 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 22:25:17 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(/* args */) :
Form("BullShit", "Presidential Pardon Form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form(target, "Presidential Pardon Form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f) :
Form(f.getTarget(), f.getName(), f.getGradeRequiredToSign(), f.getGradeRequiredToExecute())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
