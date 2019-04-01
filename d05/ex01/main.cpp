/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:47:26 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 18:56:37 by pbie             ###   ########.fr       */
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
			Form tps("TPS", 500, 30);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << "] *" << std::endl;
		}

		try
		{
			Form tps("TPS", 5, 300);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << "] *" << std::endl;
		}
		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
}
