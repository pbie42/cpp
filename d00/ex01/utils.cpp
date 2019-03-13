/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:45:32 by pbie              #+#    #+#             */
/*   Updated: 2019/03/13 13:46:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phantastic.hpp"

std::string getInfo(std::string field)
{
	std::string buffer;
	bool valid = false;

	while(!valid)
	{
		std::cout << field;
		getline(std::cin, buffer);
		if (buffer.length() > 0) valid = true;
		else std::cout << "\nCannot be left blank\n" << std::endl;
	}
	return buffer;
}

void handleFormat(std::string string)
{
	int len = 0;
	std::string str;

	len = string.length();
	if (len > 10) str = string.substr(0, 9) + ".";
	else
	{
		printSpaces(10 - len);
		str = string;
	}
	std::cout << str << "|";
}

void printSpaces(int spaces)
{
	int x = 0;
	while(x < spaces)
	{
		std::cout << " ";
		x++;
	}
}
