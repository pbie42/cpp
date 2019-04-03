/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:33:51 by pbie              #+#    #+#             */
/*   Updated: 2019/04/03 14:56:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "Need something to convert." << std::endl;
		return 0;
	}
	if (argc > 2)
	{
		std::cout << "One conversion at a time please." << std::endl;
		return 0;
	}

	std::cout << argv[0] << std::endl;
	Conversion convert(argv[1]);

	try
	{
		int cast;

		std::cout << "Char: ";
		cast = static_cast<int>(convert);

		if (cast >= 33 && cast <= 126)
			std::cout << static_cast<char>(convert) << std::endl;
		else
			std::cout << "Non Displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		int cast;

		std::cout << "int: ";
		cast = static_cast<int>(convert);
		std::cout << cast << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		float cast;

		std::cout << "float: ";
		cast = static_cast<float>(convert);
		std::cout << cast << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		double cast;

		std::cout << "double: ";
		cast = static_cast<double>(convert);
		std::cout << cast << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
