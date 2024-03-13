/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/13 16:45:05 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "\n" << WHITE_B << " Mandatory MutantStack" << NC << "\n";
		
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top : "<< mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size :"<< mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		// mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n" << WHITE_B << " Mandatory List" << NC << "\n";

		std::list<int> testList;
		testList.push_back(5);
		testList.push_back(17);
		std::cout << "top : "<< testList.back() << std::endl;
		testList.pop_back();
		std::cout << "size :"<< testList.size() << std::endl;
		testList.push_back(3);
		testList.push_back(5);
		testList.push_back(737);
		//[...]
		// mstack.push(0);
		std::list<int>::iterator it = testList.begin();
		std::list<int>::iterator ite = testList.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "\n" << WHITE_B << "std::string test !" << NC << "\n";
		
		MutantStack<std::string> stringStack;
		stringStack.push("Bonjour");
		stringStack.push("Tu");
		stringStack.push("vas");
		stringStack.push("bien ?");

		for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
			std::cout << *it << "\n";
	}
}