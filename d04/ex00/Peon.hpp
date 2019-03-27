/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:51:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 21:39:50 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
#define PEON_H

#include <iostream>
#include <string>

#include "Victim.hpp"

class Peon : public Victim
{
	private:
		/* data */
	public:
		Peon(/* args */);
		Peon(Peon const &f);
		Peon(std::string name);
		virtual ~Peon();
		Peon & operator=(Peon const &rhs);
		virtual void getPolymorphed() const;
};

#endif // PEON_H
