/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:53:30 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 14:07:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Intern(/* args */);
		Intern(Intern const &f);
		virtual ~Intern();
		Intern & operator=(Intern const &rhs);
		Form *createPardon(std::string const & target) const;
		Form *createRobotomy(std::string const & target) const;
		Form *createShrubbery(std::string const & target) const;
		Form *makeForm(std::string const & type, std::string const & target) const;
		class MakeFormException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				MakeFormException(/* args */);
				MakeFormException(MakeFormException const &f);
				virtual ~MakeFormException() throw();
				MakeFormException & operator=(MakeFormException const &rhs);
				virtual const char* what() const throw();
		};
};

#endif // INTERN_H
