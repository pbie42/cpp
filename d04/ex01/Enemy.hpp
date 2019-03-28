/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:48:11 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 18:30:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
#include <sstream>

class Enemy
{
	private:
		Enemy(/* args */);
	protected:
		std::string type;
		int hp;
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const &f);
		virtual ~Enemy();
		std::string const &getType() const;
		int getHP() const;
		void setHP(int newHP);
		Enemy & operator=(Enemy const &rhs);
		virtual void takeDamage(int);
};

std::ostream & operator<<(std::ostream & o, Enemy const & rhs);

#endif // ENEMY_H
