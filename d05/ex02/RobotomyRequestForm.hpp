/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:59:11 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 10:26:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
	protected:
		/* data */
	public:
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(RobotomyRequestForm const &f);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);
		void action() const;
};

#endif // ROBOTOMYREQUESTFORM_H
