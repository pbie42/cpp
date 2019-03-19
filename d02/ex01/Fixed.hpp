/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:24:04 by pbie              #+#    #+#             */
/*   Updated: 2019/03/19 14:45:50 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

class Fixed
{
private:
	int value;
	static const int fracBits;
public:
	Fixed();
	Fixed(Fixed const &f);
	~Fixed();
	Fixed & operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif // FIXED_H
