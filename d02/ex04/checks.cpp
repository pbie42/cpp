/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:39:06 by pbie              #+#    #+#             */
/*   Updated: 2019/03/20 14:54:03 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

bool expressionCheck(std::string str)
{
	if (str.find("+") == std::string::npos && str.find("-") == std::string::npos
		&& str.find("/") == std::string::npos && str.find("*") == std::string::npos)
		return false;
	return true;
}

bool numbersCheck(std::string str)
{
	int x = 0;
	int x2 = 0;
	bool decimal = false;

	while(str[x])
	{
		if ((str[x] < '9' && str[x] > '0') || str[x] == '.')
		{
			x2 = x;
			while(str[x2] && (str[x2] == '.' || (str[x2] < '9' && str[x2] > '0')))
			{
				if (str[x2] == '.' && !decimal) decimal = true;
				else if (str[x2] == '.' && decimal) return false;
				if (str[x2] == '.' && str[x2 + 1] && (str[x2 + 1] < '0' || str[x2 + 1] > '9')) return false;
				if (str[x2] == '.' && !str[x2 + 1]) return false;
				x2++;
			}
			decimal = false;
		}
		if (x2 > 0 && x2 > x) x = x2;
		else x++;
	}
	return true;
}

bool parenthesisCheck(std::string str)
{
	int x = 0;
	int l = 0;
	int r = 0;

	while(str[x])
	{
		if (str[x] == '(') l++;
		if (str[x] == ')') r++;
		if (r > l) return false;
		x++;
	}
	if (l != r) return false;
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

bool validateExpression(std::string str)
{
	if (!expressionCheck(str)) return false;
	if (!parenthesisCheck(str)) return false;
	if (!characterCheck(str)) return false;
	if (!numbersCheck(str)) return false;
	return true;
}
