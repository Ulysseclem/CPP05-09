/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:57 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 16:03:54 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Constructors
ScalarConverter::ScalarConverter()
{
	if (DEBUG)
		std::cout << "ScalarConverter " << GREEN << " Constructed" << NC << std::endl; 
}

ScalarConverter::~ScalarConverter()
{
	if (DEBUG)
		std::cout << "ScalarConverter " << RED << " Destroyed" << NC << std::endl; 
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void) obj;
	if (DEBUG)
		std::cout << "ScalarConverter " << GREEN << " Constructed (copy)" << NC << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this != &obj)
	{
		if (DEBUG)
			std::cout << "ScalarConverter" << YELLOW << " Assigned" << NC << std::endl; 
	}
	return *this;
}


//Members

void ScalarConverter::convert(std::string value)
{
	std::cout << value <<  std::endl;
}
