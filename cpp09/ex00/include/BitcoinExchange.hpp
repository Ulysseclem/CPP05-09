/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/13 13:41:45 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DEBUG true

#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <fstream> 
#include <sstream> 
#include "Color.hpp"

// template <typename T>
class BitcointExchange
{
	private :
		const std::map<std::string, float> _data;

	public :
	//Canonical orthodox constructor form
		BitcointExchange();
		BitcointExchange(std::map<std::string, float> data);
		~BitcointExchange();
		// BitCointExchange(const BitCointExchange& obj);
		// BitCointExchange& operator=(const BitCointExchange& obj);

	//Getters
	
	//Member function
	static bool ReadInsert(std::ifstream& File, std::map<std::string, float>& map);

	//Exception override
};

// std::ostream& operator<<(std::ostream& os, const Span& obj);


#endif