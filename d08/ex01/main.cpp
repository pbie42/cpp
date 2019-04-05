/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:40:30 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 18:16:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	Span test(10);

	test.addNumber(-500);
	test.addNumber(1);
	test.addNumber(4);
	test.addNumber(25);
	test.addNumber(90);
	test.addNumber(15);
	test.addNumber(75);
	test.addNumber(INT_MAX);
	test.addNumber(INT_MIN);
	test.printAll();
	std::cout << "\n" << std::endl;
	test.sortIt();
	test.printAll();
	std::cout << "\n" << std::endl;
	std::cout << "longest span " << test.longestSpan() << std::endl;
	std::cout << "shortest span " << test.shortestSpan() << std::endl;
	return 0;
}

