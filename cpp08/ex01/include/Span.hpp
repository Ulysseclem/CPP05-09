/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/10 18:03:04 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define DEBUG true

#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <time.h> 

// template <typename T>
class Span
{
	private :
		const unsigned int	_size;
		std::vector<int> 	_container;

	public :
	//Canonical orthodox constructor form
		Span();
		Span(const unsigned int size);
		~Span();
		Span(const Span& obj);
		Span& operator=(const Span& obj);
	
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

#endif