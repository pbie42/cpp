/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:24:04 by pbie              #+#    #+#             */
/*   Updated: 2019/03/19 17:07:26 by pbie             ###   ########.fr       */
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
	Fixed & operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);


#endif // FIXED_H
