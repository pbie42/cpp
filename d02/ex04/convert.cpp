/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:11:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/21 14:57:32 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <sstream>

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
	int expr = str[0] == '(' ? 2 : 1;

	while(str[x])
	{
		if (exprCheck(str[x]) && x > expr)
			expr = evalSymbol(str, expr, x);
		x++;
	}
	return expr;
}

std::string processOperation(std::string num1, std::string num2, char s)
{
	Fixed n1 = Fixed(std::stof(num1));
	Fixed n2 = Fixed(std::stof(num2));
	std::ostringstream ss;
	std::string total;
	switch (s)
	{
		case '+':
			ss << (n1 + n2);
			total = std::to_string((n1 + n2).toFloat());
			break;
		case '-':
			ss << (n1 - n2);
			total = std::to_string((n1 - n2).toFloat());
			break;
		case '*':
			ss << (n1 * n2);
			total = std::to_string((n1 * n2).toFloat());
			break;
		case '/':
			ss << (n1 / n2);
			total = std::to_string((n1 / n2).toFloat());
			break;
	
		default:
			break;
	}
	total = ss.str();
	std::cout << "total: " << total << std::endl;
	return total;
}

std::string findNum1(std::string str, int expr)
{
	int x = expr;
	int y;

	while(x >= 0 && !numDecCheck(str[x]))
		x--;
	y = x;
	while(y >= 0 && numDecCheck(str[y]))
		y--;
	if (y == -1 || (y == 0 && str[y] == '(')) y++;
	else if (y > 0 && str[y] == '-')
	{
		if (y - 1 >= 0 && !exprCheck(str[y - 1]))
			y++;
	}
	return str.substr(y, ++x - y);
}

std::string handleOperation(std::string str, int expr)
{
	int x = expr;
	int y = x;
	int start = 0;
	int end = 0;


	std::cout << "expr: " << x << std::endl;
	while(x >= 0 && !numDecCheck(str[x]))
		x--;
	std::cout << "x: " << x << std::endl;
	y = x;
	while(y >= 0 && numDecCheck(str[y]))
		y--;
	if (y - 1 >= 0 && str[y - 1] == '-')
	{
		std::cout << "in here bruh" << std::endl;
		if (!(y - 2 >= 0)) y--;
		// if (y - 2 >= 0 str[y - 1])
	}
	if (str[y] == '(') y++;

	std::cout << "y: " << y << std::endl;
	if (y - 1 >= 0 && (str[y - 1] == '(' || str[y - 1] == '-')){
		std::cout << "start here" << std::endl;
		start = y - 1;
	}
	else start = y;

	std::string num1 = str.substr(y, ++x - y);
	std::cout << "start: " << start << std::endl;

	x = expr;
	while(str[x] && !numDecCheck(str[x]))
		x++;
	y = x;
	while(str[y] && numDecCheck(str[y]))
		y++;

	if (str[y + 1] && str[y + 1] == ')'){
		std::cout << "end here" << std::endl;
		end = y + 1;
	}
	else end = y;

	std::cout << "end: " << end << std::endl;
	std::cout << "length: " << str.length() << std::endl;
	std::string num2 = str.substr(x, y - x);
	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;
	str.replace(start, end + 1, processOperation(num1, num2, str[expr]));
	std::cout << str << std::endl;
	return str;
}

std::string calculateExpression(std::string str)
{
	int expr = 0;
	int x = 0;

	std::cout << "expression: " << str << std::endl;
	while(expressionsCheck(str))
	{
		expr = findHighestExpression(str);
		str = handleOperation(str, expr);
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
	calculateExpression(str);
	return str;
}
