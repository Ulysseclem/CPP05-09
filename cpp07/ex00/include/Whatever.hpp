/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/04 16:19:53 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATERVER_HPP
#define WAHTEVER_HPP

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