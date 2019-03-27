/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:11:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 21:31:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <sstream>

bool exprCheck(char c);
bool nonNegCheck(char c);
bool numDecCheck(char c);
bool expressionsCheck(std::string str);
bool validateExpression(std::string str);

struct strPos {
	int x;
	int y;
};

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
	int x = -1;
	int expr = str[0] == '(' ? 2 : 1;

	while(str[++x])
		if (exprCheck(str[x]) && x > expr)
			expr = evalSymbol(str, expr, x);
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
	return total;
}

std::string handleOperation(std::string str, int expr)
{
	int x = expr;
	int y = x;
	int start = 0;
	int end = 0;
	int test = 0;

// num1
	while(x >= 0 && !numDecCheck(str[x]))
		x--;
	y = x;
	while(y >= 0 && numDecCheck(str[y]))
		y--;
	if (y == -1 || (y == 0 && str[y] == '(')) y++;

	if (nonNegCheck(str[y])) y++;
	if (y - 1 >= 0 && (str[y - 1] == '(' || str[y - 1] == '-')) start = y - 1;
	else start = y;
	std::string num1 = str.substr(y, ++x - y);

// num2
	x = expr;
	while(str[x] && !numDecCheck(str[x]))
		x++;
	y = x;
	if (str[y - 1] == '-' && exprCheck(str[y - 2])) test = y - 1;
	while(str[y] && numDecCheck(str[y]))
		y++;
	if (test > 0) x = test;
	if (str[y + 1] && str[y + 1] == ')') end = y + 1;
	else if (str[y] == ')') end = y + 1;
	else end = y;

	std::string num2 = str.substr(x, y - x);
	std::string newNum = processOperation(num1, num2, str[expr]);
	str.replace(start, end - start, newNum);
	return str;
}

std::string calculateExpression(std::string str)
{
	int expr = 0;
	int x = 0;

	while(validateExpression(str))
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
	std::string newStr;

	while(str[x])
	{
		if (str[x] == '(') start = x;
		if (str[start] == '(' && str[x] == ')') end = x;
		if (start < end)
		{
			std::string substr = str.substr(start + 1, end + 1 - start - 2);
			newStr = calculateExpression(substr);
			str.replace(start, end + 1 - start, newStr);
			start = 0;
			end = 0;
			x = 0;
			continue;
		}
		x++;
	}
	newStr = calculateExpression(str);
	str.replace(0, str.length() - start, newStr);
	std::cout << str << std::endl;
	return str;
}
