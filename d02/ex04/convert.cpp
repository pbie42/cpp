/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:11:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/21 17:21:57 by pbie             ###   ########.fr       */
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

std::string findNum2(std::string str, int expr)
{
	int x = expr;
	int y;
	int test = 0;

	while(str[x] && !numDecCheck(str[x]))
		x++;
	y = x;
	if (str[y - 1] == '-' && exprCheck(str[y - 2])) test = y - 1;
	while(str[y] && numDecCheck(str[y]))
		y++;
	if (test > 0) x = test;
	return str.substr(x, y - x);
}

std::string handleOperation(std::string str, int expr)
{
	int x = expr;
	int y = x;
	int start = 0;
	int end = 0;
	int test = 0;

// num1
	std::cout << "expr: " << x << std::endl;
	while(x >= 0 && !numDecCheck(str[x]))
		x--;
	y = x;
	while(y >= 0 && numDecCheck(str[y]))
		y--;
	if (y == -1 || (y == 0 && str[y] == '(')) y++;

	std::cout << "y: " << y << std::endl;
	std::cout << str[y] << std::endl;
	if (nonNegCheck(str[y])) y++;
	if (y - 1 >= 0 && (str[y - 1] == '(' || str[y - 1] == '-')){
		std::cout << "start here" << std::endl;
		start = y - 1;
	}
	else start = y;

	std::string num1 = str.substr(y, ++x - y);
	std::cout << "start: " << start << std::endl;

// num2
	x = expr;
	while(str[x] && !numDecCheck(str[x]))
		x++;
	y = x;
	if (str[y - 1] == '-' && exprCheck(str[y - 2])) test = y - 1;
	while(str[y] && numDecCheck(str[y]))
		y++;
	if (test > 0) x = test;
	std::cout << "str[x]: " << str[x] << std::endl;
	std::cout << "str[y]: " << str[y] << std::endl;
	if (str[y + 1] && str[y + 1] == ')'){
		std::cout << "end here" << std::endl;
		end = y + 1;
	}
	else if (str[y] == ')') end = y + 1;
	else end = y;

	std::cout << "end: " << end << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "length: " << str.length() << std::endl;
	std::string num2 = str.substr(x, y - x);
	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;
	std::cout << "str: " << str << std::endl;
	std::string newNum = processOperation(num1, num2, str[expr]);
	std::cout << "end + 1 - start: " << (end - start) << std::endl;
	str.replace(start, end - start, newNum);
	std::cout << "new str: " << str << std::endl;
	std::cout << "\n" << std::endl;
	return str;
}

std::string calculateExpression(std::string str)
{
	int expr = 0;
	int x = 0;

	while(validateExpression(str))
	{
		std::cout << "expression: " << str << std::endl;
		expr = findHighestExpression(str);
		str = handleOperation(str, expr);
		std::cout << "str before expressionsCheck: " << str << std::endl;
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
			std::cout << "convert start: " << start << std::endl;
			std::cout << "convert start: " << str[start] << std::endl;
			std::cout << "convert end: " << end << std::endl;
			std::cout << "convert end: " << str[end] << std::endl;
			std::cout << "about to calcexpr" << std::endl;
			std::string test = str.substr(start + 1, end + 1 - start - 2);
			std::cout << "test str: " << test << std::endl;
			newStr = calculateExpression(test);
			std::cout << "leaving calcexpr" << std::endl;
			str.replace(start, end + 1 - start, newStr);
			std::cout << "str after calcexpr: " << str << std::endl;
			start = 0;
			end = 0;
			x = 0;
			continue;
		}
		x++;
	}
	std::cout << "out of while" << std::endl;
	calculateExpression(str);
	return str;
}


// while(x >= 0 && !numDecCheck(str[x]))
	// 	x--;
	// std::cout << "x: " << x << std::endl;
	// y = x;
	// while(y >= 0 && numDecCheck(str[y]))
	// 	y--;
	// if (y - 1 >= 0 && str[y - 1] == '-')
	// {
	// 	std::cout << "in here bruh" << std::endl;
	// 	if (!(y - 2 >= 0)) y--;
	// 	// if (y - 2 >= 0 str[y - 1])
	// }
	// if (str[y] == '(') y++;
