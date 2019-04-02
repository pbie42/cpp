/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:50:03 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 17:41:40 by pbie             ###   ########.fr       */
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
		Form *_form;
	protected:
		/* data */
	public:
		OfficeBlock(/* args */);
		OfficeBlock(Intern *i, Bureaucrat *s, Bureaucrat *e);
		virtual ~OfficeBlock();
		void setIntern(Intern *);
		void setSigner(Bureaucrat *);
		void setExecutor(Bureaucrat *);
		void doBureaucracy(std::string const & type, std::string const & target);
		class InternException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				InternException(/* args */);
				InternException(InternException const &f);
				virtual ~InternException() throw();
				InternException & operator=(InternException const &rhs);
				virtual const char* what() const throw();
		};

		class SignerException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				SignerException(/* args */);
				SignerException(SignerException const &f);
				virtual ~SignerException() throw();
				SignerException & operator=(SignerException const &rhs);
				virtual const char* what() const throw();
		};

		class ExecutorException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				ExecutorException(/* args */);
				ExecutorException(ExecutorException const &f);
				virtual ~ExecutorException() throw();
				ExecutorException & operator=(ExecutorException const &rhs);
				virtual const char* what() const throw();
		};
};

#endif // OFFICEBLOCK_H
