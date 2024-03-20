/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:58:58 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/20 16:07:36 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcointExchange::BitcointExchange()
{
	if (DEBUG)
		std::cout << " btc created" << std::endl;
}

BitcointExchange::BitcointExchange(std::map<int, float> data) : _data(data) 
{
	if (DEBUG)
		std::cout << " btc created" << std::endl;
}

BitcointExchange::~BitcointExchange()
{
	if (DEBUG)
		std::cout << " btc destroyed" << std::endl;
}


float BitcointExchange::myStof(std::string value)
{
	std::stringstream ss(value);
	float result;
	ss >> result;
	return (result);
	
}

bool BitcointExchange::isDateValid(int year, int month, int day)
{
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) return false;
    if( month == 2) {
    	if( day > 29 ) return false;
    	if( day == 29 and ( ( year%100 )%4 != 0) ) return false;
    }
	return true;
}

bool  BitcointExchange::isCoefValid(std::string stringNbr)
{
	float nbr = myStof(stringNbr);
	if (nbr < 0)
	{
		std::cout << "Error: not a positive number";
		return false;
	}
	else if ( nbr > 1000)
	{
		std::cout << "Error: too large a number";
		return false;
	}
	return true;
}

int	BitcointExchange::dateToInt(const std::string& date)
{
	int year, month, day;
	std::string tmp;
	std::stringstream ss(date);
	
	std::getline(ss, tmp, '-');
	year = myStof(tmp);

	std::getline(ss, tmp, '-');
	month = myStof(tmp);

	std::getline(ss, tmp, '-');
	day = myStof(tmp);
	if (!isDateValid(year, month, day))
		return 0;
	return year * 10000 + month * 100 + day;
	
}

bool BitcointExchange::validateFormat(const std::string& input, char sep)
{
    std::istringstream iss(input);
    int year, month, day;
    char separator1, separator2, comma;
    std::string lastPart;

    if (!(iss >> year >> separator1 >> month >> separator2 >> day >> comma))
        return false;
    else if (separator1 != '-' || separator2 != '-' || comma != sep)
        return false;
    else if (!(iss >> lastPart))
        return false;

    std::istringstream lastPartStream(lastPart);
    double value;
    if (!(lastPartStream >> value))
        return false;

    char c;
    if (lastPartStream >> c)
        return false;
    return true;
}

bool BitcointExchange::ReadInsert(std::ifstream& file, std::map<int, float>& map)
{
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (!validateFormat(line, ','))
			return false;
		std::stringstream ss(line);
		std::string key, value;
		if (std::getline(ss, key, ',') && std::getline(ss, value))
			map[dateToInt(key)] = myStof(value);
		else 
			return false;
	}
	return true;
}