/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/12 11:56:21 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "Color.hpp"
#include <iostream>

template <typename givenType>
void swap (givenType& a, givenType& b)
{
	givenType tmp = a;
	a = b;
	b = tmp;
}

template <typename givenType>
givenType& min (givenType& a, givenType& b)
{
	if (a == b)
		return b;
	else if (a < b)
		return a;
	else 
		return b;
}

template <typename givenType>
givenType& max (givenType& a, givenType& b)
{
	if (a == b)
		return b;
	else if (a > b)
		return a;
	else 
		return b;
}

#endif 