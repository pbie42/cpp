/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:55:45 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 12:55:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window(WINDOW *win) :
_win(win)
{
}

Window::Window(const Window &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Window::~Window()
{
}

Window & Window::operator=(Window const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

WINDOW *Window::getWin() const
{
	return this->_win;
}
int Window::getLeft() const
{
	return this->_left;
}
int Window::getRight() const
{
	return this->_right;
}
int Window::getTop() const
{
	return this->_top;
}
int Window::getBottom() const
{
	return this->_bottom;
}
void Window::setLeft(int left)
{
	this->_left = left;
}
void Window::setRight(int right)
{
	this->_right = right;
}
void Window::setTop(int top)
{
	this->_top = top;
}
void Window::setBottom(int bottom)
{
	this->_bottom = bottom;
}

void Window::setBounds(int right, int left, int top, int bottom)
{
	this->setRight(right);
	this->setLeft(left);
	this->setTop(top);
	this->setBottom(bottom);
}
