/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:46:04 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 12:55:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <ncurses.h>

class Window
{
	private:
		Window();
		WINDOW *_win;
		int _left;
		int _right;
		int _top;
		int _bottom;
	protected:
		/* data */
	public:
		Window(WINDOW *win);
		Window(Window const &f);
		virtual ~Window();
		Window & operator=(Window const &rhs);
		WINDOW *getWin() const;
		int getLeft() const;
		int getRight() const;
		int getTop() const;
		int getBottom() const;
		void setLeft(int);
		void setRight(int);
		void setTop(int);
		void setBottom(int);
		void setBounds(int, int, int, int);
};

#endif // WINDOW_H
