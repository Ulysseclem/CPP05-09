/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:22:43 by uclement          #+#    #+#             */
/*   Updated: 2024/02/29 17:43:10 by uclement         ###   ########.fr       */
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
	return (uintptr_t)ptr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (Data *)raw;
}