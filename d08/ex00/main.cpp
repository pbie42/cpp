/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:39:30 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 15:00:42 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	for(int i = 0; i < 100; i++)
		v.push_back(i);
	try
	{
		int test = easyfind(v, 200);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		int test = easyfind(v, 55);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::list<int> l;
	for(int i = 0; i < 100; i++)
		l.push_back(i);
	try
	{
		int test = easyfind(l, 630);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		int test = easyfind(l, 63);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
