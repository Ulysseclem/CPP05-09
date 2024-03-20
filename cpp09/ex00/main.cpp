/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/20 16:28:52 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


void errorExit(std::string msg)
{
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{  
	if (ac != 2)
		errorExit ("Wrong number of arguments");
		
	std::ifstream inputFile;
	std::ifstream dataFile;
	inputFile.open(av[1]);
	dataFile.open("data.csv");
	if(!inputFile.is_open() || !dataFile.is_open())
		errorExit ("Error: could not open file.");
	
	std::map<int, float> dataMap;
	if (!BitcointExchange::ReadInsert(dataFile, dataMap))
		errorExit("Issue with data.csv");
	for (std::map<int, float>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
	{
		if (it->first == 0)
			errorExit("Issue with data.csv");
	}

	std::string date, value, line;
	std::getline(inputFile, line);
	if (line != "date | value")
		std::cout << "Error : Wrong header => " << line <<  "expected : date | value" << std::endl;
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		if (!std::getline(ss, date, '|') || !std::getline(ss, value) || value == " ")
			std::cout << "Error bad input => " << line << std::endl;
		else if (!BitcointExchange::validateFormat(line, '|'))
			std::cout << "Error bad input => " << line << std::endl;
		else if ( BitcointExchange::dateToInt(date) == 0)
			std::cout << "Error bad input => " << date << std::endl;
		else if (!BitcointExchange::isCoefValid(value))
			std::cout << " => " << value << std::endl;
		else
		{
			for (std::map<int, float>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
			{
				if (it->first - BitcointExchange::dateToInt(date)== 0)
				{
					std::cout << date << " => " << value << " = " << it->second * BitcointExchange::myStof(value) << std::endl;
					break;
				}
				else if (it->first - BitcointExchange::dateToInt(date) > 0)
				{
					std::map<int, float>::iterator prevIt = it;
					--prevIt;
					std::cout << date << " => " << value << " = " << prevIt->second * BitcointExchange::myStof(value) << std::endl;
					break;
				}
			    if (++it == dataMap.end()) // dernier element de la liste
				{
            		--it;
					std::cout << date << " => " << value << " = " << it->second * BitcointExchange::myStof(value) << std::endl;
        		} 
				else
 		           --it;
			}
		}
	}
	exit(EXIT_SUCCESS);
}

