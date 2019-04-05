/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:26:05 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 23:27:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	if (mstack.size())
		std::cout << "mstack has something" << std::endl;
	else
		std::cout << "mstack has nothing" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	std::cout << "size: " << mstack.size() << std::endl;
	if (mstack.size())
		std::cout << "mstack has something" << std::endl;
	else
		std::cout << "mstack has nothing" << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\n" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;

	MutantStack<int> testing(mstack);
	if (testing.size())
		std::cout << "testing has something" << std::endl;
	else
		std::cout << "testing has nothing" << std::endl;
	testing.push(5);
	testing.push(17);
	std::cout << "top: " << testing.top() << std::endl;
	testing.pop();
	std::cout << "size: " << testing.size() << std::endl;
	testing.push(3);
	testing.push(5);
	testing.push(737);
	std::cout << "size: " << testing.size() << std::endl;
	if (testing.size())
		std::cout << "testing has something" << std::endl;
	else
		std::cout << "testing has nothing" << std::endl;
	testing.push(0);
	MutantStack<int>::iterator tit = testing.begin();
	MutantStack<int>::iterator tite = testing.end();
	++tit;
	--tit;
	std::cout << "\n" << std::endl;
	while (tit != tite)
	{
	std::cout << *tit << std::endl;
	++tit;
	}
	
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	MutantStack<int> newTest = mstack;
	if (newTest.size())
		std::cout << "newTest has something" << std::endl;
	else
		std::cout << "newTest has nothing" << std::endl;
	newTest.push(5);
	newTest.push(17);
	std::cout << "top: " << newTest.top() << std::endl;
	newTest.pop();
	std::cout << "size: " << newTest.size() << std::endl;
	newTest.push(3);
	newTest.push(5);
	newTest.push(737);
	std::cout << "size: " << newTest.size() << std::endl;
	if (newTest.size())
		std::cout << "newTest has something" << std::endl;
	else
		std::cout << "newTest has nothing" << std::endl;
	newTest.push(0);
	MutantStack<int>::iterator nit = newTest.begin();
	MutantStack<int>::iterator nite = newTest.end();
	++nit;
	--nit;
	std::cout << "\n" << std::endl;
	while (nit != nite)
	{
	std::cout << *nit << std::endl;
	++nit;
	}

	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	std::list<int> lstack;
	if (lstack.size())
		std::cout << "lstack has something" << std::endl;
	else
		std::cout << "lstack has nothing" << std::endl;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "top: " << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << "size: " << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	std::cout << "size: " << lstack.size() << std::endl;
	if (lstack.size())
		std::cout << "lstack has something" << std::endl;
	else
		std::cout << "lstack has nothing" << std::endl;
	lstack.push_back(0);
	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();
	++lit;
	--lit;
	std::cout << "\n" << std::endl;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	return 0;
}
