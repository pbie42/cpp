/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:16:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/22 12:18:05 by pbie             ###   ########.fr       */
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
		newStr.erase(found, 1);
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
			convert(str);
		x++;
	}
	return 0;
}

