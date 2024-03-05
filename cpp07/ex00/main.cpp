/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/04 16:45:02 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <string>


class Test
{
    public:
        Test( int n ) : _n(n) {}
        bool operator==( Test const & rhs ) const { return (this->_n == rhs._n); }
        bool operator!=( Test const & rhs ) const { return (this->_n != rhs._n); }
        bool operator>( Test const & rhs ) const { return (this->_n > rhs._n); }
        bool operator<( Test const & rhs ) const { return (this->_n < rhs._n); }
        bool operator>=( Test const & rhs ) const { return (this->_n >= rhs._n); }
        bool operator<=( Test const & rhs ) const { return (this->_n <= rhs._n); }
        int get( void ) const { return this->_n; }
    private:
        int _n;
};

std::ostream & operator<<( std::ostream & os, Test const & rhs ) { os << rhs.get(); return os; }

int main()
{
	{
	int a = 2;
	int b = 3;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
	Test a(2), b(4), c(7);
    if (a != c)
        std::cout << "a != c" << std::endl;
    a = c;
    if (a == c)
        std::cout << "a == c" << std::endl;
    if (a > b)
        std::cout << "a > b" << std::endl;
    if (a < b)
        std::cout << "a < b" << std::endl;
    if (b >= a)
        std::cout << "b >= a" << std::endl;
    if (b <= a)
        std::cout << "b <= a" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap<Test>(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max( a, b ) = " << max<Test>( a, b ) << std::endl;
    std::cout << "min( a, b ) = " << min<Test>( a, b ) << std::endl;
	}
}


