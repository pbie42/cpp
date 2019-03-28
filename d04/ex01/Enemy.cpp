/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:48:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 18:46:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(/* args */)
{
}

Enemy::Enemy(int hp, std::string const & type) :
type(type),
hp(hp)
{
}

Enemy::Enemy(const Enemy &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Enemy::~Enemy()
{
}

void Enemy::takeDamage(int dmg)
{
	int currentHP = this->getHP();
	int totalDmg = currentHP - dmg;

	if (dmg < 0) return;
	if ((totalDmg) < 0) totalDmg = 0;
	std::cout << this->getType() << " has taken " << dmg << " points of damage" << std::endl;
	this->setHP(totalDmg);
}

Enemy & Enemy::operator=(Enemy const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setHP(rhs.getHP());
	this->type = rhs.getType();
	return *this;
}

std::string const &Enemy::getType() const
{
	return (this->type);
}

int Enemy::getHP() const
{
	return this->hp;
}

void Enemy::setHP(int newHP)
{
	this->hp = newHP;
}

std::ostream & operator<<(std::ostream & o, Enemy const & rhs)
{
	std::stringstream ss;

	ss << rhs.getType() << " has " << rhs.getHP() << " HP";
	o << ss.str();
	return o;
}
