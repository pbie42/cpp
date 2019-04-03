/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:31:19 by pbie              #+#    #+#             */
/*   Updated: 2019/04/03 18:11:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(/* args */)
{
}

Conversion::Conversion(const char *input) :
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
	if (std::strcmp(this->_data, "-inf") == 0 || std::strcmp(this->_data, "-inff") == 0
		|| std::strcmp(this->_data, "inf") == 0 || std::strcmp(this->_data, "inff") == 0)
		throw ConversionError();
	double x = 0;
	char *end;

	try
	{
		if((x = std::strtod(this->_data, &end)) == 0)
		{
			int x = 0;
			while(this->_data[x])
				x++;
			
			if (x == 1)
				return static_cast<char>(this->_data[0]);
			else
				throw ConversionError();
		}
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<int>(x);
}

Conversion::operator int() const
{
	if (std::strcmp(this->_data, "-inf") == 0 || std::strcmp(this->_data, "-inff") == 0
		|| std::strcmp(this->_data, "inf") == 0 || std::strcmp(this->_data, "inff") == 0)
		throw ConversionError();
	double x = 0;
	char *end;

	try
	{
		if((x = std::strtod(this->_data, &end)) == 0)
		{
			int x = 0;
			int others = 0;
			while(this->_data[x])
			{
				if (this->_data[x] >= '1' && this->_data[x] <= '9')
					others++;
				x++;
			}
			
			if (x == 1 || others == 0)
			{
				if (this->_data[0] == '0')
					return static_cast<int>(0);
				return static_cast<int>(this->_data[0]);
			}
			else
				throw ConversionError();
		}
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<int>(x);
}

Conversion::operator double() const
{
	double x = 0.0;
	char *end;
	try
	{
		if((x = std::strtod(this->_data, &end)) == 0)
		{
			int x = 0;
			int others = 0;
			while(this->_data[x])
			{
				if (this->_data[x] >= '1' && this->_data[x] <= '9')
					others++;
				x++;
			}
			
			if (x == 1 || others == 0)
			{
				if (this->_data[0] == '0')
					return static_cast<double>(0);
				return static_cast<double>(this->_data[0]);
			}
			else
				throw ConversionError();
		}
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<double>(x);
}

Conversion::operator float() const
{
	double x = 0.0;
	char *end;
	try
	{
		if((x = std::strtod(this->_data, &end)) == 0)
		{
			int x = 0;
			int others = 0;
			while(this->_data[x])
			{
				if (this->_data[x] >= '1' && this->_data[x] <= '9')
					others++;
				x++;
			}
			
			if (x == 1 || others == 0)
			{
				if (this->_data[0] == '0')
					return static_cast<float>(0);
				return static_cast<float>(this->_data[0]);
			}
			else
				throw ConversionError();
		}
	}
	catch(const std::exception& e)
	{
		throw ConversionError();
	}
	return static_cast<float>(x);
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
