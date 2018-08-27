/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:39:27 by pbie              #+#    #+#             */
/*   Updated: 2018/08/27 12:55:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int			main(int argc, char** argv){

	int x;
	int y;
	char c;

	x = 0;
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[++x]) {
		y = 0;
		while (argv[x][y]) {
			if (argv[x][y] >= 'a' && argv[x][y] <= 'z') {
				c = argv[x][y] - 32;
				std::cout << c;
			}
			else std::cout << argv[x][y];
			y++;
		}
	}
	std::cout << std::endl;

	return (0);
}
