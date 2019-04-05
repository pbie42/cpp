/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:40:30 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 20:41:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

void printIt(int i)
{
	std::cout << i << std::endl;
}

int main()
{
	Span test(10);
	std::vector<int> v;

	srand(time(0) + rand());

	for(size_t i = 0; i < 100; i++)
		v.push_back(rand() % 2000);

	std::cout << "v.begin " << *v.begin() << std::endl;
	std::cout << "v.end " << *v.end() << std::endl;

	for_each(v.begin(), v.end(), printIt);
	
	// test.addNumber(INT_MAX);
	// test.addNumber(INT_MIN);
	test.setRange(v.begin(), v.end());
	test.printAll();
	std::cout << "\n" << std::endl;
	test.sortIt();
	test.printAll();
	std::cout << "\n" << std::endl;
	std::cout << "longest span " << test.longestSpan() << std::endl;
	std::cout << "shortest span " << test.shortestSpan() << std::endl;
	return 0;
}

