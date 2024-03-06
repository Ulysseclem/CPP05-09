/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/06 16:42:06 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstring>


int main()
{
	Array<int> listA(5);
	std::cout << listA.getArray() << "\n";
	for (unsigned int i = 0; i < listA.size(); i++)
		listA[i] = (i) * 2;

	Array<int> listB(listA);
	for (unsigned int i = 0; i < listB.size(); i++)
		listB[i] = (i) * -4;
	std::cout << "\nList B \n";
	for (unsigned int i = 0; i < listB.size(); i++)
		std::cout << listB[i] << " ";
	std::cout << "\n\nList A \n";
	for (unsigned int i = 0; i < listA.size(); i++)
		std::cout << listA[i] << " ";

	std::cout << "\n\n";	
	try
	{
		std::cout << listA[2] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		std::cout << listA[8] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	Array<int> listC;
	std::cout << listC.getArray() << "\n";
}
