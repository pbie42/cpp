/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:59:11 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 11:26:00 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
	protected:
		/* data */
	public:
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(ShrubberyCreationForm const &f);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);
		void action() const;
};

#endif // SHRUBBERYCREATIONFORM_H
