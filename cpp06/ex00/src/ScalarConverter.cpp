/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:57 by uclement          #+#    #+#             */
/*   Updated: 2024/03/08 13:25:26 by uclement         ###   ########.fr       */
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

enum type {
    CHAR,
    INT,
    FLOAT,
    FLOAT_PSEUDO,
    DOUBLE,
    DOUBLE_PSEUDO,
	ERROR,
};

static type findValueType(const std::string& value)
{
	int 	countChar = 0;
	int 	countNbr = 0;
	int 	countDot = 0;
	bool	isFloat = false;
	bool	isDeci = false;
	bool	hasOperator = false;
	
	if (value == "-inf" || value == "+inf" || value == "nan")
		return DOUBLE_PSEUDO;
	if (value == "-inff" || value =="+inff" || value == "nanf")
		return FLOAT_PSEUDO;
	if (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]))
		return CHAR;
	else
	{
		for (int i = 0; value[i]; i++)
		{
			if (value[0] == '+' || value[0] == '-')
				hasOperator = true;
			if (std::isdigit(value[i]))
				countNbr++;
			if (std::isalpha(value[i]))
			{
				if (value[i] == 'f')
					isFloat = true;
				countChar++;
			}
			if (value[i] == '.')
				countDot++;
			if (value[i] == '.' && std::isdigit(value[i + 1]))
				isDeci = true;
		}
		if (countChar > 1 || countDot > 1)
			return ERROR;
		else if ((countNbr  + hasOperator) == (int)value.length())
			return INT;
		else if (countDot && isFloat && isDeci)
			return FLOAT;
		else if (countDot && !isFloat && isDeci)
			return DOUBLE;
		return ERROR;
	}
}

static void charCasting(char c)
{
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}

static void intCasting(int nbr)
{
	char c = static_cast<char>(nbr);

	if (nbr >= std::numeric_limits<char>::min() && nbr <= std::numeric_limits<char>::max())
	{
		if (std::isprint(c))
			std::cout << "char : " << c << std::endl;
		else
			std::cout << "Not displayable" << std::endl;
	}
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << nbr << std::endl;
	if (nbr > 999999 || nbr < -999999 )
	{
		std::cout << "float : " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(nbr) << std::endl;
	}
	else
	{
		std::cout << "float : " << static_cast<float>(nbr) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(nbr) << ".0" << std::endl;
	}
}

static void floatCasting(float f)
{
	char c = static_cast<char>(f);

	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		if (std::isprint(c))
			std::cout << "char : " << c << std::endl;
		else
			std::cout << "Not displayable" << std::endl;
	}
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << static_cast<int>(f) << std::endl;
	if (f > 999999 || f < -999999 )
	{
		std::cout << "float : " << f << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(f) << std::endl;
	}
	else
	{
		std::cout << "float : " << f << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(f)  << ".0" << std::endl;
	}
}

static void doubleCasting(double d)
{
	char c = static_cast<char>(d);

	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		if (std::isprint(c))
			std::cout << "char : " << c << std::endl;
		else
			std::cout << "Not displayable" << std::endl;
	}
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
	std::cout << "double : " << d << ".0" << std::endl;
}

static void valueIsPseudo(const std::string& value, type valueType)
{
	std::cout << "Char : Impossible" << std::endl;
	std::cout << "Int : Impossible" << std::endl;
	if (valueType == FLOAT)
	{
		std::cout << "Float : " << value << std::endl;
		std::cout << "Double : " << value.substr(0, value.length() - 1) << std::endl;
	}
	else if (valueType == DOUBLE)
	{
		std::cout << "Float : " << value <<  "f" << std::endl;
		std::cout << "Double : " << value << std::endl;
	}
}

static void valueIsChar(const std::string& value)
{
	std::stringstream stream(value);
	char c;

	stream >> c;
	charCasting(c);
}

static void valueIsInt(const std::string& value)
{
	std::stringstream stream(value);
	int nbr;

	stream >> nbr;
	intCasting(nbr);
}

static void valueIsFloat(const std::string& value)
{
	std::stringstream stream(value);
	float nbr;

	stream >> nbr;
	floatCasting(nbr);
}

static void valueIsDouble(const std::string& value)
{
	std::stringstream stream(value);
	double nbr;

	stream >> nbr;
	doubleCasting(nbr);
}

void ScalarConverter::convert(const std::string& value)
{
	switch(findValueType(value))
	{
		case CHAR :
			std::cout << WHITE_B << "Input is a char" << NC << std::endl;
			valueIsChar(value);
			break;
		case INT :
			std::cout << WHITE_B << "Input is an int" << NC << std::endl;
			valueIsInt(value);
			break;
		case FLOAT :
			std::cout << WHITE_B << "Input is a float" << NC << std::endl;
			valueIsFloat(value);
			break;
		case FLOAT_PSEUDO :
			std::cout << WHITE_B << "Input is a float" << NC << std::endl;
			valueIsPseudo(value, FLOAT);
			break;
		case DOUBLE :
			std::cout << WHITE_B << "Input is a double" << NC << std::endl;
			valueIsDouble(value);
			break;
		case DOUBLE_PSEUDO :
			std::cout << WHITE_B << "Input is a double" << NC << std::endl;
			valueIsPseudo(value, DOUBLE);
			break;
		case ERROR :
			std::cout << RED << "Input is an error" << NC << std::endl;
			break;
	}
}