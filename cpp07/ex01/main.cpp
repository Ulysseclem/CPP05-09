/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/12 12:14:42 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <cstring>

class Awesome 
{
	public : 
		Awesome(void) :_n(42) {return;}
		int get(void) const {return this->_n;}
	private :
		int _n;	
};
std::ostream &operator<<(std::ostream& os, Awesome const &obj) { os << obj.get(); return os;}


template<typename T>
void print (T const& x)
{
	std::cout << x << std::endl; 
	return;
}


int main()
{
    {
		std::cout << "\n" << WHITE_B << "MY TEST" << NC << "\n";

        const char *test = "Bonjour";
        size_t len = std::strlen(test);
        iter(test, len, increPrint);
    }
    {
        int * test = new int[5];
        for (int i = 0; i < 5; ++i) {
            test[i] = i; }
        iter(test, 5, increPrint);
        delete[] test;
    }
	{
		std::cout << "\n" << WHITE_B << "MANDATORY" << NC << "\n";
		
		int tab[] = {0,1,2,3,4};
		Awesome tab2[5];

		iter(tab, 5, print);
		iter(tab2, 5, print);

		return (0);

	}
}


