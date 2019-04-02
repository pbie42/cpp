/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:47:26 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 16:09:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


void testForms(Bureaucrat &b, Form &f)
{

	try
	{
		b.executeForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		b.executeForm(f);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}



int main()
{
	try
	{
		Bureaucrat rob("Rob", 140);
		Bureaucrat todd("Todd", 5);
		Bureaucrat bob("bob", 20);

		PresidentialPardonForm ppf("Dan Hadley");
		std::cout << ppf << std::endl;
		RobotomyRequestForm rbr("Dan Hadley");
		std::cout << rbr << std::endl;
		ShrubberyCreationForm scf("Office");
		std::cout << rbr << std::endl;
		std::cout << "\n" << std::endl;

		testForms(rob, ppf);
		std::cout << "\n" << std::endl;
		testForms(rob, rbr);
		std::cout << "\n" << std::endl;
		testForms(rob, scf);
		std::cout << "\n" << std::endl;
		testForms(todd, ppf);
		std::cout << "\n" << std::endl;
		testForms(todd, rbr);
		std::cout << "\n" << std::endl;
		testForms(todd, scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
