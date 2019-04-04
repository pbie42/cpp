/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:47:49 by pbie              #+#    #+#             */
/*   Updated: 2019/04/04 18:02:55 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Test {

	public:
		Test( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }

	private:
	int _n;
};


std::ostream & operator<<( std::ostream & o, Test const & rhs ) { o << rhs.get(); return o; }

template <typename T>
void iter(T *array, int len, void(*f)(T const &))
{
	if (array)
	{
		for(int i = 0; i < len; i++)
		{
			f(array[i]);
		}
	}
}

template <typename T>
void printItem(T item)
{
	std::cout << item << std::endl;
}

int main()
{
	std::string strArr[6] = { "Oliver", "Jennifer", "Alex", "Juliana", "Nick", "Josie" };
	int intArr[6] = { 1, 2, 3, 4, 5, 6 };
	Test tab[5];

	iter(strArr, 6, printItem);
	iter(intArr, 6, printItem);
	iter(tab, 5, printItem);
	return 0;
}

