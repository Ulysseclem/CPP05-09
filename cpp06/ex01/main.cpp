/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/02/29 17:48:04 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data head;
	Data tail;

	head.value = 1;
	head.next = NULL;
	tail.value = 2;
	head.next = &tail;
	
	std::cout << head.value << std::endl;
	uintptr_t ptr = Serializer::serialize(&head);

	Data *old;

	old = Serializer::deserialize(ptr);
	std::cout << old->value << std::endl;

}