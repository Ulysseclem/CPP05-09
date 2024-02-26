/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 14:04:18 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
{
	std::cout << std::endl;
	Bureaucrat employe_1("Boss", 1);
	Bureaucrat employe_2("Stagiaire", 150);
	Form form("Nouveau Batiment", 5, 10);
	
	std::cout << form << std::endl;
	
	try
	{
		employe_1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		employe_2.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
{
	std::cout << std::endl << std::endl;
	Form a1("Salaires", 149, 149);
	Form a2 = a1;
	Form a3(a2);

	Bureaucrat employe_1("Stagiaire", 149);
	try
	{
		employe_1.signForm(a1);
		std::cout << a1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	employe_1.decrementGrade(1);
	try
	{
		employe_1.signForm(a3);
		std::cout << a3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
}