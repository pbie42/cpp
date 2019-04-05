/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:39:30 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 16:19:28 by pbie             ###   ########.fr       */
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
		std::cout << "looking for 200" << std::endl;
		int test = easyFind(v, 200);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "looking for 99" << std::endl;
		int test = easyFind(v, 99);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "looking for 55" << std::endl;
		int test = easyFind(v, 55);
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
		std::cout << "looking for 630" << std::endl;
		int test = easyFind(l, 630);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "looking for 63" << std::endl;
		int test = easyFind(l, 63);
		std::cout << "We found " << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
