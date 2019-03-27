/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:51:17 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 16:42:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>
#include <sstream>

class Victim
{
	private:
		/* data */
	protected:
		std::string name;
	public:
		Victim(/* args */);
		Victim(std::string name);
		Victim(Victim const &f);
		virtual ~Victim();
		Victim & operator=(Victim const &rhs);
		std::string getName() const;
		void setName(std::string name);
		virtual void getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

#endif // VICTIM_H
