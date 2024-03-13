/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/13 16:13:29 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include "Color.hpp"



class EasyFindException : public std::exception {
	public:
		const char *what() const throw() {
			return "Exception: number not found in container";
   		}
};

template <typename T>
int easyfind (const T& container, int toFind)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it != container.end())
		return (std::distance(container.begin(),it));
	else
		throw EasyFindException();
}

#endif