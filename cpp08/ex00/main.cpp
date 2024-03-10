/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/10 16:47:54 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{  
    std::vector<int> test;

    test.push_back(10);
    test.push_back(20);
    test.push_back(30);

    try 
    {
        std::cout <<  ::easyfind(test, 10) << " <- Position of the element in the container" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        std::cout <<  ::easyfind(test, 11) << " <- Position of the element in the container" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try 
    {
        std::cout <<  ::easyfind(lst, 20) << " <- Position of the element in the container" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        std::cout <<  ::easyfind(lst, 11) << " <- Position of the element in the container" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::deque<int> deque;

    deque.push_back(10);
    deque.push_back(20);
    deque.push_back(30);

    try 
    {
        std::cout <<  ::easyfind(deque, 30) << " <- Position of the element in the container" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        std::cout <<  ::easyfind(deque, 11) << " <- Position of the element in the container" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

