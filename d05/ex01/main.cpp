/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:47:26 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 20:42:19 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	try
	{
		Bureaucrat rob("Rob", 40);
		Bureaucrat todd("Todd", 5);

		try
		{
			Form tps("TPS", 5, 30);
			std::cout << tps << std::endl;
			try
			{
				rob.signForm(tps);
				std::cout << tps << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
			try
			{
				todd.signForm(tps);
				std::cout << tps << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "\n" << std::endl;
		try
		{
			Form tps("TPS", 5, 300);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Form tps("TPS", -1, 100);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
