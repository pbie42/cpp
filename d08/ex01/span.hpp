/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:25:52 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 18:59:07 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <string>
#include <vector>

struct isLesserSpan
{
	isLesserSpan(const double &span_set) : currentSpan(span_set) {}
	double currentSpan;
	bool operator()(const int & f, const int & s)
	{
		// std::cout << "currentSpan " << currentSpan << std::endl;
		// std::cout << "f " << f << std::endl;
		// std::cout << "s " << s << std::endl;
		if (s - f >= 0 && s - f < currentSpan)
			return true;
		return false;
	}
};

class Span
{
	private:
		Span(/* args */);
		std::vector<int> *_v;
		unsigned int _max;
		unsigned int _count;
		double _span;
	protected:
		/* data */
	public:
		Span(unsigned int N);
		Span(Span const &f);
		virtual ~Span();
		Span & operator=(Span const &rhs);
		void addNumber(int);
		void printNumber(int) const;
		void printAll() const;
		void sortIt();
		double longestSpan();
		double shortestSpan();
		template <typename T>
		void setRange(typename T::iterator, typename T::iterator);
};

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

template <typename T>
void Span::setRange(typename T::iterator begin, typename T::iterator end)
{
	
	for(typename T::iterator i = begin, unsigned int x = 0; i != end && x < this->_count; i++, x++)
	{
		
	}
	
}

#endif // SPAN_H
