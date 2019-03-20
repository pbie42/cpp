/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:24:22 by pbie              #+#    #+#             */
/*   Updated: 2019/03/19 18:42:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::Fixed(int const i)
{
	this->setRawBits(i << this->fracBits);
}

Fixed::Fixed(float const f)
{
	this->setRawBits(roundf(f * (1 << this->fracBits)));
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)(this->value / (float)(1 << this->fracBits));
}

int Fixed::toInt(void) const
{
	return (int)(this->value >> this->fracBits);
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	this->setRawBits(rhs.getRawBits());
	return *this;
}

// Prefix
Fixed & Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool Fixed::operator==(Fixed const &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits()) return true;
	return false;
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	if (this->getRawBits() != rhs.getRawBits()) return true;
	return false;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	if (this->getRawBits() > rhs.getRawBits()) return true;
	return false;
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits()) return true;
	return false;
}

bool Fixed::operator<(Fixed const &rhs) const
{
	if (this->getRawBits() < rhs.getRawBits()) return true;
	return false;
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits()) return true;
	return false;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const int Fixed::fracBits = 8;
