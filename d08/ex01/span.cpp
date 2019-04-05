/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:10:28 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 20:52:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(/* args */)
{
}

Span::Span(unsigned int N) :
_max(N),
_count(0),
_span(0)
{
	this->_v = new std::vector<int>;
}

Span::Span(const Span &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Span::~Span()
{
}

Span & Span::operator=(Span const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void Span::printNumber(int i) const
{
	std::cout << i << std::endl;
}

void Span::printAll() const
{
	for_each(this->_v->begin(), this->_v->end(), std::bind1st(std::mem_fun(&Span::printNumber), this));
}

void Span::addNumber(int i)
{
	if (this->_count < this->_max)
	{
		this->_v->push_back(i);
		this->_count++;
	}
}

void Span::sortIt()
{
	sort(this->_v->begin(), this->_v->end());
}

double Span::shortestSpan()
{
	this->sortIt();
	this->_span = this->longestSpan();
	std::vector<int>::iterator itr;
	for(unsigned int i = 0; i < this->_count; i++)
	{
		itr = adjacent_find(this->_v->begin(), this->_v->end(), isLesserSpan(this->_span));
		if (itr != this->_v->end())
		{
			int pos = itr - this->_v->begin();
			this->_span = static_cast<double>(this->_v->at(pos + 1)) - static_cast<double>(this->_v->at(pos));
		}
	}
	return this->_span;
}

double Span::longestSpan()
{
	this->sortIt();
	int first = this->_v->at(0);
	int second = this->_v->at(this->_count - 1);
	return static_cast<double>(second) - static_cast<double>(first);
}
