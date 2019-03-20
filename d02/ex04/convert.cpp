/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:11:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/20 18:48:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>

bool exprCheck(char c);
bool numDecCheck(char c);
bool expressionsCheck(std::string str);

int evalSymbol(std::string str, int v1, int v2)
{
	if (str[v1] == '+' && (str[v2] == '+' || str[v2] == '-')) return v1;
	if (str[v1] == '-' && (str[v2] == '+' || str[v2] == '-')) return v1;
	if (str[v1] == '*' && (str[v2] == '+' || str[v2] == '-' || str[v2] == '/' || str[v2] == '*')) return v1;
	if (str[v1] == '/' && (str[v2] == '+' || str[v2] == '-' || str[v2] == '/' || str[v2] == '*')) return v1;
	return v2;
}

int findHighestExpression(std::string str)
{
	int x = 0;
	int expr = 0;

	while(str[x])
	{
		if (exprCheck(str[x]))
			expr = evalSymbol(str, expr, x);
		x++;
	}
	return expr;
}

int handleOperation(std::string str, int expr)
{
	int x = expr;
	int y = x;
	std::cout << "x: " << x << std::endl;

	while(x >= 0 && !numDecCheck(str[x]))
		x--;
	y = x;
	while(y >= 0 && numDecCheck(str[y]))
		y--;
	y++;
	std::cout << "first num: " << str.substr(y, x - y == 0 ? 1 : x - y) << std::endl;

	x = expr;
	while(str[x] && !numDecCheck(str[x]))
		x++;
	y = x;
	while(str[y] && numDecCheck(str[y]))
		y++;
	std::cout << "second num: " << str.substr(x, y - x) << std::endl;
	return 0;
}

std::string calculateExpression(std::string str)
{
	int expr = 0;
	int x = 0;

	while(expressionsCheck(str) && x < 20)
	{
		expr = findHighestExpression(str);
		handleOperation(str, expr);
		x++;
	}
	return str;
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
			calculateExpression(str.substr(start, end - start));
		}
		start = 0;
		end = 0;
		x++;
	}
	return str;
}
