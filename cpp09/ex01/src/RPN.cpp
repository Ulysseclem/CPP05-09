/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:58:58 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/27 17:02:46 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdlib.h> 


RPN::RPN()
{
	_sizeNbr = 0;
	_sizeOp = 0;
	_result = 0;
}

RPN::~RPN() {}

int RPN::myStoi(std::string value)
{
	std::stringstream ss(value);
	int result;
	ss >> result;
	return (result);
}

void RPN::pushDigit(char input) {
	int num = input - '0'; // Convert char to int
	_nbr.push(num); // Push the int into the stack
	_sizeNbr++;
}

void RPN::pushDigitNeg(char input) {
	int num = input - '0'; // Convert char to int
	_nbr.push(num * -1); // Push the int into the stack
	_sizeNbr++;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isValid(std::string input)
{
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
		std::cout << "Wrong input" << std::endl; return false; }
		
	for (size_t i = 0; i < input.length() - 1; i++)
	{
		if (std::isdigit(input[i]) && input[i + 1] != ' ') { // espace apres nbr
			std::cout << "Spacing issue" << std::endl; return false; }
		else if ((input[i] == '/' || input[i] == '*') && (input[i + 1] != ' ')){ // espace apres / et *
			std::cout << "Operator issue" << std::endl; return false; }
		else if ((input[i] == '+' || input[i] == '-') && ((input[i + 1] != ' ') \
		&& !std::isdigit(input[i + 1]))){ // espace apres + et -
			std::cout << "Operator issue" << std::endl; return false; }
		else if (i != (input.length() - 1) && isOperator(input[i]) && (isOperator(input[i + 2]) && !std::isdigit(input[i + 3]))) {
			std::cout << "Operator issue" << std::endl; return false; }
	}
	return true;
}

void RPN::plusOperand()
{
	_nbr.pop();
	_result += _nbr.top();
}

void RPN::minusOperand()
{
	_nbr.pop();
	_result -= _nbr.top();
}

void RPN::mulOperand()
{
	_nbr.pop();
	_result *= _nbr.top();
}

void RPN::divOperand()
{
	_nbr.pop();
	if (_nbr.top() == 0) {
		std::cout << "division by 0" << std::endl; exit(0); }
	_result /=_nbr.top();
}

void RPN::process2()
{
	switch (_op.top()) {
		case '+' :
			plusOperand();
			break;
		case '-' :
			minusOperand();
			break;
		case '*' :
			mulOperand();
			break;
		case '/' :
			divOperand();
			break;
	}
}

void RPN::process()
{
	// print();
	
	_result = _nbr.top();
	while (!_op.empty())
	{
		process2();
		_op.pop();
	}
	std::cout << "result : " << _result << std::endl; 
}

void RPN::toStack(std::string input)
{
	if (!isValid(input)) // verifie les espace et les op (pas leurs nombre)
		return exit(0);
	for (int i = input.length(); i >= 0; i--)
	{
		if (std::isdigit(input[i])) // push dans _nbr
		{
			if (i != 0 && input[i - 1] == '-')
				pushDigitNeg(input[i]);
			else
				pushDigit(input[i]);
		}
		else if (isOperator(input[i])) //  push dans _op
		{
			_op.push(input[i]);
			_sizeOp++;
		}
	}
	if (_sizeNbr != (_sizeOp + 1)) {
		std::cout << "Wrong format (not right amount of operator/nbr)" << std::endl; exit(0); }
	process();
}

void RPN::print()
{
	while (!this->_nbr.empty())
	{
		std::cout << _nbr.top() << " ";
		_nbr.pop();
	}
}