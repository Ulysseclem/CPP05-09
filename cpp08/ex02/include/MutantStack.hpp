/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/13 16:38:04 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define DEBUG true

#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <iterator>
#include <list>
#include "Color.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
	//Canonical orthodox constructor form
		MutantStack(void) {};
		~MutantStack(void) {};
		MutantStack(const MutantStack &obj) {*this = obj;}
		MutantStack &operator=(const MutantStack& obj) 
		{
			// we use std::stack operator = to properly assign 
			std::stack<int>::operator=(obj);
			return *this;
		}
		/*stack default container does contain iterator, we can therefore create our own iterator with those.*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin() {return this->c.begin();}
		iterator	end() {return this->c.end();}
};

#endif