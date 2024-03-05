/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/04 17:11:43 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "Color.hpp"
#include <iostream>

template <typename T>
void increPrint (T x)
{
	x++;
	std::cout << x << std::endl;
}

template <typename ptr>
void iter (ptr *a, int b, void (*f)(ptr))
{
	int i = 0;
	while (i < b)
	{
		f(a[i]);
		i++;
	}
}


#endif 