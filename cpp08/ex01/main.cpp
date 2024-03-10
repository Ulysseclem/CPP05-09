/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/10 18:29:56 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// STD::LARGEST ELEMENT TO LOOK INTO

int main()
{  
    Span test(5);
    try
    {
        test.addNumber(1);
        test.addNumber(9);
        test.addNumber(14);
        // test.addNumber(9);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << test.longestSpan() << std::endl;
    std::cout << test.shortestSpan()<< std::endl;

    try 
    {
        std::vector<int> bigVector(1000);
        Span myVector(1000);
        
        srand (time(NULL));

        std::generate(bigVector.begin(), bigVector.end(),randomInRange);
        myVector.addNumber(bigVector.begin(), bigVector.end());
        std::cout << myVector.shortestSpan() << std::endl;
        std::cout << myVector.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    

    
}

