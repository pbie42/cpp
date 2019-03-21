/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:16:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/21 13:26:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

bool validateExpression(std::string str);
std::string convert(std::string str);

std::string removeSpaces(std::string str)
{
	size_t found;
	std::string newStr = str;
	while((found = newStr.find(' ')) != std::string::npos)
	{
		newStr.erase(found, 1);
	}
	std::cout << "erased newStr: " << newStr << std::endl;
	return newStr;
}

int main(int argc, char const *argv[])
{
	int x = 1;
	std::string str;

	if (argc <= 1) return 0;
	while(x < argc)
	{
		str = removeSpaces(argv[x]);
		if (!validateExpression(str))
		{
			std::cout << argv[x] << " is not a valid expression" << std::endl;
			x++;
			continue;
		}
		else
		{
			std::cout << argv[x] << " is a valid expression" << std::endl;
			convert(str);
		}
		x++;
	}
	return 0;
}

