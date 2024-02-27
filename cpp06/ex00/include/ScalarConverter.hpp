/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:05 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 15:56:54 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include "Color.hpp"

#ifndef DEBUG
# define DEBUG true
#endif

class ScalarConverter
{
	private :
			ScalarConverter();
	public :

		//Orthodox Canonical Class Form
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter& operator=(const ScalarConverter &obj);
		~ScalarConverter();

		//Members
		static void convert(std::string value);
};

#endif