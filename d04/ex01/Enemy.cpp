/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:48:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:53:56 by pbie             ###   ########.fr       */
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
	if ((currentHP - dmg) < 0 || dmg < 0) return
	this->setHP(currentHP - dmg);
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
