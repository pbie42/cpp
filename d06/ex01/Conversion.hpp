/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:09:29 by pbie              #+#    #+#             */
/*   Updated: 2019/04/03 17:11:01 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <string>
#include <sstream>

class Conversion
{
	private:
		/* data */
		Conversion(/* args */);
	protected:
		const char* _data;
	public:
		Conversion(const char*);
		Conversion(Conversion const &f);
		virtual ~Conversion();
		Conversion & operator=(Conversion const &rhs);
		class ConversionError : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				ConversionError(/* args */);
				ConversionError(ConversionError const &f);
				virtual ~ConversionError() throw();
				ConversionError & operator=(ConversionError const &rhs);
				virtual const char* what() const throw();
		};
		operator char() const;
		operator int() const;
		operator double() const;
		operator float() const;
};

#endif // CONVERSION_H
