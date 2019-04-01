/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:47:26 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 16:55:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat rob("Rob", 149);
		Bureaucrat gob("Gob", 2);

		rob.decGrade();
		std::cout << rob << std::endl;
		rob.decGrade();
		std::cout << rob << std::endl;
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
	

	try
	{
		Bureaucrat bob("Bob", 0);
		Bureaucrat todd("Todd", 151);
		std::cout << bob << std::endl;
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
	return 0;
}
