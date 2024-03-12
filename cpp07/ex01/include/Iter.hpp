/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/12 12:13:55 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "Color.hpp"
#include <iostream>

template <typename T>
void increPrint (T const& x)
{
	std::cout << x << std::endl;
}

template <typename ptr>
void iter (ptr *a, int b, void (*f)(const ptr&))
{
	int i = 0;
	while (i < b)
	{
		f(a[i]);
		i++;
	}
}


#endif 