/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:36:54 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 19:44:45 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <sstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
		Form(/* args */);
	protected:
		/* data */
	public:
		Form(std::string, int, int);
		Form(Form const &f);
		virtual ~Form();
		Form & operator=(Form const &rhs);
		std::string const &getName() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		bool getSigned() const;
		void beSigned(Bureaucrat &);

		class GradeTooLowException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				GradeTooLowException(/* args */);
				GradeTooLowException(GradeTooLowException const &f);
				virtual ~GradeTooLowException() throw();
				GradeTooLowException & operator=(GradeTooLowException const &rhs);
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				GradeTooHighException(/* args */);
				GradeTooHighException(GradeTooHighException const &f);
				virtual ~GradeTooHighException() throw();
				GradeTooHighException & operator=(GradeTooHighException const &rhs);
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif // FORM_H
