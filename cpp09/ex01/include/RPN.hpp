/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/27 16:24:55 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define DEBUG true

#include <iostream>
#include <string>
#include <exception>
#include <stack>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <fstream> 
#include <sstream> 
#include <stdint.h>


// template <typename T>
class RPN
{
	private :
		std::stack<int> _nbr;
		std::stack<char> _op;
		int _sizeNbr;
		int _sizeOp;
		float _result;

	public :

	//Canonical orthodox constructor form
		RPN();
		~RPN();

	//Getters
	
	//Member function
		void print();
		void toStack(std::string input);
		int myStoi(std::string value);
		bool isValid(std::string input);
		void pushDigit(char input);
		void pushDigitNeg(char input);
		void process();

		void plusOperand();
		void minusOperand();
		void mulOperand();
		void divOperand();
		void  process2();


	//Exception override
};

// std::ostream& operator<<(std::ostream& os, const Span& obj);


#endif