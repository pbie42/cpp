/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:47:26 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 16:54:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 46);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 70);
	OfficeBlock ob;
	std::cout << "\n" << std::endl;
	try
	{
		ob.doBureaucracy("Shrubbery Creation", "Home");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n" << std::endl;
	ob.setIntern(&idiotOne);

	try
	{
		ob.doBureaucracy("Shrubbery Creation", "Home");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n" << std::endl;
	ob.setSigner(&bob);
	try
	{
		ob.doBureaucracy("Shrubbery Creation", "Home");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n" << std::endl;
	ob.setExecutor(&hermes);
	try
	{
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		ob.doBureaucracy("robotomy request", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		ob.doBureaucracy("shrubbery creation", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
