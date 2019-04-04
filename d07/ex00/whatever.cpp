/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:32:53 by pbie              #+#    #+#             */
/*   Updated: 2019/04/04 17:59:17 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Test {


	public:
		Test( int n ) : _n( n ) {}
		bool operator==( Test const & rhs ) { return (this->_n == rhs._n); }
		bool operator!=( Test const & rhs ) { return (this->_n != rhs._n); }
		bool operator>( Test const & rhs ) { return (this->_n > rhs._n); }
		bool operator<( Test const & rhs ) { return (this->_n < rhs._n); }
		bool operator>=( Test const & rhs ) { return (this->_n >= rhs._n); }
		bool operator<=( Test const & rhs ) { return (this->_n <= rhs._n); }
		int get() const { return _n; }

	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Test const & rhs ) { o << rhs.get(); return o; }


template <typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

template <typename T>
void swap(T &a, T &b)
{
	T temp(a);
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	Test six(6);
	Test seven(7);
	::swap( six, seven );
	std::cout << "six = " << six << ", seven = " << seven << std::endl;
	std::cout << "min( six, seven ) = " << ::min( six, seven ) << std::endl;
	std::cout << "max( six, seven ) = " << ::max( six, seven ) << std::endl;
	return 0;
}
