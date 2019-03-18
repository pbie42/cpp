/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:53:10 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 15:25:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main()
{
	Logger file = Logger("test.txt");
	file.log("logToConsole", "Fuck You");
	file.log("logToFile", "and fuck you Too");
	return 0;
}
