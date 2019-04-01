/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:47:26 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 18:38:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat rob("Rob", 148);

		try
		{
			rob.decGrade();
			std::cout << rob << std::endl;
			rob.decGrade();
			std::cout << rob << std::endl;
			rob.decGrade();
			std::cout << rob << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << "] *" << std::endl;
		}
		
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		Bureaucrat gob("Gob", 3);

		try
		{
			gob.incGrade();
			std::cout << gob << std::endl;
			gob.incGrade();
			std::cout << gob << std::endl;
			gob.incGrade();
			std::cout << gob << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << "] *" << std::endl;
		}
		
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}


	std::cout << "\n" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}

	std::cout << "\n" << std::endl;
	try
	{
		Bureaucrat todd("Todd", 151);
		std::cout << todd << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
	return 0;
}
