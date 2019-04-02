/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:58:40 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 16:12:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(/* args */) :
Form("BullShit", "Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form(target, "Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f) :
Form(f.getTarget(), f.getName(), f.getGradeRequiredToSign(), f.getGradeRequiredToExecute())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void RobotomyRequestForm::action() const
{
	srand(time(0) + rand());
	int random = rand() % 2;
	if (random > 0)
		std::cout << this->getTarget() << " has NOT been robotomized." << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
}
