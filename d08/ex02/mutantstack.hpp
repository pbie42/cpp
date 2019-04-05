/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:25:34 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 22:39:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>

template< typename T>
class MutantStack : public std::stack<T>
{
	private:
		std::vector<T> _stack;
	protected:
		/* data */
	public:
		typedef typename std::vector<T>::iterator iterator;
		MutantStack(/* args */);
		MutantStack(MutantStack const &f);
		virtual ~MutantStack();
		MutantStack & operator=(MutantStack const &rhs);
		bool empty() const;
		unsigned int size() const;
		T & top();
		void push(T);
		void pop();
		typename std::vector<T>::iterator begin();
		typename std::vector<T>::iterator end();
};


template< typename T>
MutantStack<T>::MutantStack(/* args */)
{
}

template< typename T>
MutantStack<T>::MutantStack(const MutantStack &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

template< typename T>
MutantStack<T>::~MutantStack()
{
}

template< typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

template< typename T>
bool MutantStack<T>::empty() const
{
	return this->_stack.empty();
}

template< typename T>
void MutantStack<T>::push(T element)
{
	this->_stack.push_back(element);
}

template< typename T>
void MutantStack<T>::pop()
{
	this->_stack.pop_back();
}

template< typename T>
T & MutantStack<T>::top()
{
	return this->_stack.back();
}

template< typename T>
unsigned int MutantStack<T>::size() const
{
	return this->_stack.size();
}

template< typename T>
typename std::vector<T>::iterator MutantStack<T>::begin()
{
	return this->_stack.begin();
}

template< typename T>
typename std::vector<T>::iterator MutantStack<T>::end()
{
	return this->_stack.end();
}



#endif // MUTANTSTACK_H
