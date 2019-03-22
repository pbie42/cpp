/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:39:06 by pbie              #+#    #+#             */
/*   Updated: 2019/03/22 12:16:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

bool numCheck(char c)
{
	if (c >= '0' && c <= '9') return true;
	return false;
}

bool decCheck(char c)
{
	if (c != '.') return false;
	return true;
}

bool numDecCheck(char c)
{
	if (decCheck(c) || numCheck(c)) return true;
	return false;
}

bool exprCheck(char c)
{
	if (c == '+' || c == '-' || c == '/' || c =='*') return true;
	return false;
}

bool nonNegCheck(char c)
{
	if (c == '+' || c == '/' || c =='*') return true;
	return false;
}

bool negCheck(std::string str, int x)
{
	int z = x;
	int count = 0;
	while(str[z] && str[z] == '-')
	{
		count++;
		z++;
	}
	if (count > 2) return false;
	return true;
}

bool expressionsCheck(std::string str)
{
	int x = 0;
	bool plus = false;
	bool minus = false;
	bool divide = false;
	bool multiply = false;

	while(str[x])
	{
		if (!plus && str[x] == '+') plus = true;
		if (!minus && str[x] == '-') minus = true;
		if (!divide && str[x] == '/') divide = true;
		if (!multiply && str[x] == '*') multiply = true;
		if (str[x] == '(' && str[x + 1] && nonNegCheck(str[x + 1])) return false;
		if ((str[x] == '(') && str[x + 1] && str[x + 1] == '-' && str[x + 2] && exprCheck(str[x + 2])) return false;
		if (x == 0 && str[x] == '-' && str[x + 1] && str[x + 1] == '-') return false;
		if (exprCheck(str[x]) && str[x + 1] && nonNegCheck(str[x + 1])) return false;
		if (exprCheck(str[x]) && str[x + 1] && str[x + 1] == '-' && !negCheck(str, x)) return false;
		x++;
	}
	if (!plus && !minus && !divide && !multiply) return false;
	return true;
}

bool numbersCheck(std::string str)
{
	int x = 0;
	int x2 = 0;
	int numCount = 0;
	bool decimal = false;
	bool isDec = false;

	while(str[x])
	{
		if (numDecCheck(str[x]))
		{
			x2 = x;
			while(str[x2] && numDecCheck(str[x2]))
			{
				isDec = decCheck(str[x2]);
				if (isDec && !decimal) decimal = true;
				else if (isDec && decimal) return false;
				if (isDec && str[x2 + 1] && !numCheck(str[x2 + 1])) return false;
				if (isDec && !str[x2 + 1]) return false;
				x2++;
			}
			decimal = false;
			numCount++;
		}
		if (x2 > 0 && x2 > x) x = x2;
		else x++;
	}
	if (numCount < 2) return false;
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
		if (str[x] == '(' && str[x + 1] && str[x + 1] == ')')
			return false;
		if (str[x] == '(' && (x - 1 > 0) && (!exprCheck(str[x - 1]) && str[x - 1] != '('))
			return false;
		if (str[x] == ')' && str[x + 1] && (!exprCheck(str[x + 1]) && str[x + 1] != ')'))
			return false;
		if (str[x] == ')' && str[x - 1] && exprCheck(str[x - 1]))
			return false;
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
	if (nonNegCheck(str[0])) return false;
	if (!expressionsCheck(str)) return false;
	if (!parenthesisCheck(str)) return false;
	if (!characterCheck(str)) return false;
	if (!numbersCheck(str)) return false;
	return true;
}
