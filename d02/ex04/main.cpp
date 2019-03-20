/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:16:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/20 13:42:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

bool validateExpression(std::string str);

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
		if (!validateExpression(argv[x]))
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

