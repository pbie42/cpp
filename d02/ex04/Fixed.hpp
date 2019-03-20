/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:24:04 by pbie              #+#    #+#             */
/*   Updated: 2019/03/19 18:41:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fracBits;
public:
	Fixed();
	Fixed(int const i);
	Fixed(float const f);
	Fixed(Fixed const &f);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed & operator=(Fixed const &rhs);
	Fixed & operator++();
	Fixed operator++(int);
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	bool operator>(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);


#endif // FIXED_H
