/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 11:16:05 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat employee_1("Ted", 5);
	Bureaucrat employee_2 = employee_1;
	Bureaucrat employee_3(employee_2);

	std::cout << employee_1 << std::endl;
	std::cout << employee_2 << std::endl;
	std::cout << employee_3 << std::endl;

	try
	{
		Bureaucrat WrongGrade("WrongGrade", 151);
		std::cout << WrongGrade << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat WrongGrade2("WrongGrade", 0);
		std::cout << WrongGrade2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		employee_1.incrementGrade(5);
		std::cout << employee_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		employee_1.incrementGrade(4);
		std::cout << employee_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		employee_1.decrementGrade(149);
		std::cout << employee_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}