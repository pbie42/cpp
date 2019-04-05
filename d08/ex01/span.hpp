/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:25:52 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 20:53:18 by pbie             ###   ########.fr       */
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
		void setRange(T, T);
};

template <typename T>
void Span::setRange(T begin, T end)
{
	for_each(begin, end, std::bind1st(std::mem_fun(&Span::addNumber), this));
}

#endif // SPAN_H
