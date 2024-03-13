/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:58:58 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/13 13:41:35 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcointExchange::BitcointExchange()
{
	if (DEBUG)
		std::cout << " btc created" << std::endl;
}

BitcointExchange::BitcointExchange(std::map<std::string, float> data) : _data(data) 
{
	if (DEBUG)
		std::cout << " btc created" << std::endl;
}

BitcointExchange::~BitcointExchange()
{
	if (DEBUG)
		std::cout << " btc destroyed" << std::endl;
}


float myStof(std::string value)
{
	std::stringstream ss(value);
	float result;
	ss >> result;
	return (result);
	
}

bool BitcointExchange::ReadInsert(std::ifstream& file, std::map<std::string, float>& map)
{
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string key, value;
		if (std::getline(ss, key, ',') && std::getline(ss, value))
			map[key] = myStof(value);
	}
	return true;
}