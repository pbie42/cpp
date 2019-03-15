/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:28:05 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 11:32:41 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string brainString = "HI THIS IS BRAIN";
	std::string *pString = &brainString;
	std::string &rString = brainString;

	std::cout << "Pointer string says: " << *pString << std::endl;
	std::cout << "Reference string says: " << rString << std::endl;
	return 0;
}
