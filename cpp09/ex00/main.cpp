/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/13 12:52:43 by uclement         ###   ########.fr       */
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
		errorExit ("error with opening files");
	
	std::map<std::string, float> inputMap;
	if (!BitcointExchange::ReadInsert(dataFile, inputMap))
		errorExit ("error inside input file");
	for (std::map<std::string, float>::iterator it = inputMap.begin(); it != inputMap.end(); ++it)
		std::cout << it->first << " | " << it->second << "\n";
	exit(EXIT_SUCCESS);
}

