/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:16:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/19 18:43:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "a " << a << std::endl;

	std::cout << "b " << b << std::endl;

	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;

	Fixed testA = Fixed(5);
	Fixed testB = Fixed(5);
	Fixed testC = Fixed(5.5f);
	Fixed testD = Fixed(10);

	std::cout << "testA == testB: " << ((testA == testB) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA == testC: " << ((testA == testC) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA != testB: " << ((testA != testB) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA != testC: " << ((testA != testC) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA > testB: " << ((testA > testB) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA >= testB: " << ((testA >= testB) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA <= testC: " << ((testA <= testC) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA < testC: " << ((testA < testC) == 0 ? "false" : "true") << std::endl;
	std::cout << "testA + testC: " << (testA + testC) << std::endl;
	std::cout << "testA + testB: " << (testA + testB) << std::endl;
	std::cout << "testD - testB: " << (testD - testB) << std::endl;
	std::cout << "testD - testC: " << (testD - testC) << std::endl;

	return (0);
}
