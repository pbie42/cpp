/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:59:59 by pbie              #+#    #+#             */
/*   Updated: 2019/04/04 21:27:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T *_typeArray;
		unsigned int _len;
	protected:
		/* data */
	public:
		Array(/* args */);
		Array(unsigned int);
		Array(Array const &f);
		virtual ~Array();
		Array<T> & operator=(Array const &rhs);
		T & operator[](unsigned int);
		unsigned int size() const;
		class OutOfBoundsException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				OutOfBoundsException(/* args */);
				OutOfBoundsException(OutOfBoundsException const &f);
				virtual ~OutOfBoundsException() throw();
				OutOfBoundsException & operator=(OutOfBoundsException const &rhs);
				virtual const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array(/* args */) :
_len(0)
{
	this->_typeArray = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int len) :
_len(len)
{
	this->_typeArray = new T[len];
}

template <typename T>
Array<T>::Array(const Array &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_typeArray = new T[f._len];
	this->_len = f._len;
	for(unsigned int i = 0; i < f._len; i++)
	{
		this->_typeArray[i] = *new T(f._typeArray[i]);
	}
	*this = f;
}

template <typename T>
Array<T>::~Array()
{

}

template <typename T>
Array<T> & Array<T>::operator=(Array const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_typeArray = new T[rhs._len];
	this->_len = rhs._len;
	for(unsigned int i = 0; i < rhs._len; i++)
	{
		this->_typeArray[i] = *new T(rhs._typeArray[i]);
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int idx)
{
	if (idx >= this->_len) throw OutOfBoundsException();
	return this->_typeArray[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_len;
}


// Out Of Bounds Exception -----------------------------------------------------

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(/* args */)
{
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

template <typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException() throw()
{
}

template <typename T>
typename Array<T>::OutOfBoundsException & Array<T>::OutOfBoundsException::operator=(OutOfBoundsException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Selection is out of bounds of the array");
}

#endif // ARRAY_H
