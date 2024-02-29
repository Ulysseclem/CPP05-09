/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:05 by uclement          #+#    #+#             */
/*   Updated: 2024/02/29 14:41:57 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <ctype.h>
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
		static void convert(const std::string& value);
};

#endif