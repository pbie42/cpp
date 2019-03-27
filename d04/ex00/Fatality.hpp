/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fatality.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:41:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 22:14:37 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FATALITY_H
#define FATALITY_H

#include <iostream>
#include <string>

#include "Victim.hpp"

class Fatality : public Victim
{
	private:
		/* data */
	public:
		Fatality(/* args */);
		Fatality(std::string name);
		Fatality(Fatality const &f);
		virtual ~Fatality();
		Fatality & operator=(Fatality const &rhs);
		virtual void getPolymorphed() const;
};

#endif // FATALITY_H
