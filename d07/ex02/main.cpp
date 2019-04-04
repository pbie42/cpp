/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:01:35 by pbie              #+#    #+#             */
/*   Updated: 2019/04/04 21:27:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> test(7);
	test[0] = 6;
	test[1] = 8;
	std::cout << "len " << test.size() << std::endl;
	std::cout << "test[0] " << test[0] << std::endl;
	std::cout << "test[1] " << test[1] << std::endl;

	Array<int> another(test);
	std::cout << "len " << another.size() << std::endl;
	std::cout << "another[0] " << another[0] << std::endl;
	std::cout << "another[1] " << another[1] << std::endl;

	another[0] = 15;
	std::cout << "another[0] " << another[0] << std::endl;
	std::cout << "test[0] " << test[0] << std::endl;

	return 0;
}
