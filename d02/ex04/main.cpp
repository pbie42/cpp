/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:16:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/20 12:01:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

bool expressionCheck(std::string str)
{
	if (str.find("+") == std::string::npos && str.find("-") == std::string::npos
		&& str.find("/") == std::string::npos && str.find("*") == std::string::npos)
		return false;
	return true;
}

bool characterCheck(std::string str)
{
	int x = -1;
	while(str[++x])
		if (str[x] != '.' && (str[x] < '0' || str[x] > '9') && str[x] != ' '
			&& str[x] != '+' && str[x] != '-' && str[x] != '*' && str[x] != '/'
			&& str[x] != '(' && str[x] != ')')
				return false;
	return true;
}

void handleExpression(std::string str)
{
	std::cout << str << " is a valid expression" << std::endl;
}

int main(int argc, char const *argv[])
{
	int x = 1;

	if (argc <= 1) return 0;
	while(x < argc)
	{
		if (!expressionCheck(argv[x]) || !characterCheck(argv[x]))
		{
			std::cout << argv[x] << " is not a valid expression" << std::endl;
			x++;
			continue;
		}
		else
		{
			handleExpression(argv[x]);
		}
		x++;
	}
	return 0;
}

