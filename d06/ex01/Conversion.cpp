/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:31:19 by pbie              #+#    #+#             */
/*   Updated: 2019/04/03 14:53:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(/* args */)
{
}

Conversion::Conversion(std::string input) :
_data(input)
{
}

Conversion::Conversion(const Conversion &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Conversion::~Conversion()
{
}

Conversion & Conversion::operator=(Conversion const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_data = rhs._data;
	}
	return *this;
}

Conversion::operator char() const
{
	int res = 0;

	try
	{
		res = std::stoi(this->_data);
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<char>(res);
}

Conversion::operator int() const
{
	int res = 0;

	try
	{
		res = std::stoi(this->_data);
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<int>(res);
}

Conversion::operator double() const
{
	double res = 0;

	try
	{
		res = std::stod(this->_data);
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<double>(res);
}

Conversion::operator float() const
{
	float res = 0;

	try
	{
		res = std::stof(this->_data);
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return res;
}

// Conversion Error ------------------------------------------------------------

Conversion::ConversionError::ConversionError(/* args */)
{
}

Conversion::ConversionError::ConversionError(const ConversionError &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Conversion::ConversionError::~ConversionError() throw()
{
}

Conversion::ConversionError & Conversion::ConversionError::operator=(ConversionError const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Conversion::ConversionError::what() const throw()
{
	return ("Impossible");
}
