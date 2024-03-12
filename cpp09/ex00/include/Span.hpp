/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/11 16:07:25 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define DEBUG true

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <time.h>
#include "Color.hpp"

// template <typename T>
class Span
{
	private :
		unsigned int	_size;
		std::vector<int> 	_container;
		Span();

	public :
	//Canonical orthodox constructor form
		Span(const unsigned int size);
		~Span();
		Span(const Span& obj);
		Span& operator=(const Span& obj);

	//Getters
		const std::vector<int>& getContainer() const;
	
	//Member function
		void addNumber(int nbr);
		void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		int	shortestSpan();
		int	longestSpan();


	//Exception override
	class SpanSizeException : public std::exception 
	{
		public:
			const char *what() const throw()
			{
				return "Exception: Span size issue";
			}
	};
};

std::ostream& operator<<(std::ostream& os, const Span& obj);


#endif