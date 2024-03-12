/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/12 11:59:16 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <string>


class Test
{
    private:
        int _nbr;
		
    public:
        Test( int n ) : _nbr(n) {}
        bool operator==( Test const & obj ) const { return (this->_nbr == obj._nbr); }
        bool operator!=( Test const & obj ) const { return (this->_nbr != obj._nbr); }
        bool operator>( Test const & obj ) const { return (this->_nbr > obj._nbr); }
        bool operator<( Test const & obj ) const { return (this->_nbr < obj._nbr); }
        bool operator>=( Test const & obj ) const { return (this->_nbr >= obj._nbr); }
        bool operator<=( Test const & obj ) const { return (this->_nbr <= obj._nbr); }
        int get( void ) const { return this->_nbr; }
};

std::ostream & operator<<( std::ostream & os, Test const & obj ) { os << obj.get(); return os; }

int main()
{
	{
	std::cout << WHITE_B << "MANDATORY INT" << NC << "\n";
	
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
	}
	{
	std::cout << "\n" << WHITE_B << "MANDATORY FLOAT" << NC << "\n";

	float a = 2;
	float b = 3;
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
	}
	{
	std::cout << "\n" <<WHITE_B << "TEST CLASS WITH OVERLOADED OPERATOR" << NC << "\n";

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


