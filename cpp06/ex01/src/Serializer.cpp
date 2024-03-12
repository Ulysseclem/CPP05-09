/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:22:43 by uclement          #+#    #+#             */
/*   Updated: 2024/03/12 11:35:00 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};
	
Serializer::Serializer(const Serializer& obj)
{
	*this = obj;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	(void)obj;
	return *this;
}

Serializer::~ Serializer() {};

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t> (ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}