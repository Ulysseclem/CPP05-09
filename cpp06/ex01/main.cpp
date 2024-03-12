/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/12 11:33:56 by uclement         ###   ########.fr       */
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
	
	std::cout << "value head " << head.value << std::endl;
	std::cout << "Adress head : " << &head << std::endl;
	uintptr_t ptr = Serializer::serialize(&head);
	std::cout << "Adress before serialize: " << &ptr << std::endl;

	Data *old;


	old = Serializer::deserialize(ptr);
	std::cout << "value old " << old->value << std::endl;
	std::cout << "Adress after serialize: " <<old << std::endl;

} 