/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:11:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/20 14:29:50 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>

bool expressionCheck(std::string str);

std::string calculateExpression(std::string str)
{

}

std::string convert(std::string str)
{
	int x = 0;
	int start = 0;
	int end = 0;

	while(str[x])
	{
		if (str[x] == '(') start = x;
		if (str[start] == '(' && str[x] == ')') end = x;
		if (start < end)
		{
			std::string calculated = calculateExpression(str.substr(start, end - start));
		}
		x++;
	}
	
}
