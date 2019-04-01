/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:59:11 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 22:25:24 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
	protected:
		/* data */
	public:
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(PresidentialPardonForm const &f);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
		void action() const;
};

#endif // PRESIDENTIALPARDONFORM_H
