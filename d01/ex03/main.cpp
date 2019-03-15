/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:17:31 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 11:22:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>

int main()
{
	ZombieHorde zombieHorde = ZombieHorde(10);
	zombieHorde.announce();

	std::cout << "\nLeaving main\n" << std::endl;
	return 0;
}
