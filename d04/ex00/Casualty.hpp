/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casualty.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:41:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 21:52:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASUALTY_H
#define CASUALTY_H

#include <iostream>
#include <string>

#include "Victim.hpp"

class Casualty : public Victim
{
	private:
		/* data */
	public:
		Casualty(/* args */);
		Casualty(std::string name);
		Casualty(Casualty const &f);
		virtual ~Casualty();
		Casualty & operator=(Casualty const &rhs);
		virtual void getPolymorphed() const;
};

#endif // CASUALTY_H
