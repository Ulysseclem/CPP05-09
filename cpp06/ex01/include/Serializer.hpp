/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:10:38 by uclement          #+#    #+#             */
/*   Updated: 2024/02/29 17:44:39 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>


typedef struct Data {
	int value;
	Data* next;	
} Data;

class Serializer
{
	private :
		Serializer();
		
	public :
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		~ Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



#endif