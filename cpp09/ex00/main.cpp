/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/12 17:22:48 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <exception> 


void errorExit(std::string msg)
{
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}


int main(int ac, char **av)
{  
	if (ac != 2)
		errorExit ("Wrong number of arguments");
		
	std::ifstream file;
	file.open(av[1]);
	if(!file.is_open())
		errorExit ("error with opening input");
	
	
	exit(EXIT_SUCCESS);
}

