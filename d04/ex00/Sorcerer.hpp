/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:41:53 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 14:41:41 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
#define SORCERER_H

#include <iostream>
#include <string>
#include <sstream>

#include "Victim.hpp"

class Sorcerer
{
	private:
		Sorcerer(/* args */);
		std::string name;
		std::string title;
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &f);
		~Sorcerer();
		Sorcerer & operator=(Sorcerer const &rhs);
		std::string getName() const;
		void setName(std::string name);
		std::string getTitle() const;
		void setTitle(std::string title);
		void polymorph(Victim const &) const;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif // SORCERER_H
