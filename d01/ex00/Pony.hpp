/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:51:34 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 13:43:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
#define PONY_H

#include <string>

class Pony
{
	private:
		std::string name;
		std::string color;
		int height;

	public:
		Pony(std::string n, std::string c, int h);
		~Pony();
		void neigh(void);
};

#endif // PONY_H
