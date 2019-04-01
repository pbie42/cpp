/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:43:20 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 15:45:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <sstream>

class Bureaucrat
{
	private:
		Bureaucrat(/* args */);
	protected:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string, int);
		Bureaucrat(Bureaucrat const &f);
		virtual ~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &rhs);
		std::string const &getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		class GradeTooHighException : public std::exception
		{
			private:
			protected:
				/* data */
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const &f);
				virtual ~GradeTooHighException() throw();
				GradeTooHighException & operator=(GradeTooHighException const &rhs);
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
			protected:
				/* data */
			public:
				GradeTooLowException(/* args */);
				GradeTooLowException(GradeTooLowException const &f);
				virtual ~GradeTooLowException() throw();
				GradeTooLowException & operator=(GradeTooLowException const &rhs);
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif // BUREAUCRAT_H
