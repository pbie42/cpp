/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:36:54 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 22:25:33 by pbie             ###   ########.fr       */
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
		const std::string _target;
		bool _signed;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
		Form(/* args */);
	protected:
		/* data */
	public:
		Form(std::string, std::string, int, int);
		Form(Form const &f);
		virtual ~Form() = 0;
		Form & operator=(Form const &rhs);
		std::string const &getName() const;
		std::string const &getTarget() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		bool getSigned() const;
		void beSigned(Bureaucrat &);
		virtual void action() const = 0;
		void execute(Bureaucrat const & executor) const;

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

		class NotSignedException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				NotSignedException(/* args */);
				NotSignedException(NotSignedException const &f);
				virtual ~NotSignedException() throw();
				NotSignedException & operator=(NotSignedException const &rhs);
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif // FORM_H
