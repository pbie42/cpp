/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:35:35 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 13:51:23 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void ponyOnTheStack(void)
{
	Pony::Pony steve = Pony::Pony("Steve", "plum", 120);
	steve.neigh();
	std::cout << "Leaving ponyOnTheStack" << std::endl;
	std::cout << "" << std::endl;
}

void ponyOnTheHeap(void)
{
	Pony::Pony *harold = new Pony::Pony("Harold", "pink", 100);
	harold->neigh();
	delete harold;
	std::cout << "Leaving ponyOnTheHeap" << std::endl;
	std::cout << "" << std::endl;
}


int main()
{
	std::cout << "Entering ponyOnTheStack" << std::endl;
	ponyOnTheStack();
	std::cout << "Entering ponyOnTheHeap" << std::endl;
	ponyOnTheHeap();
	return 0;
}
