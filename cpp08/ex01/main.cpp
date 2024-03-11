/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/11 16:10:02 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{  
    {
        std::cout << WHITE_B << "COPY TEST \n" << NC;
        Span A (5);
        A.addNumber(1);
        A.addNumber(9);
        A.addNumber(14);
        std::cout << "list : " << A << std::endl;
        Span B(A);
        std::cout << "list : " << B << std::endl;
        Span C = A;
        std::cout << "list : " << C << std::endl;
        A.addNumber(16);
        B.addNumber(100);
        C.addNumber(9999);

        std::cout << "list : " << A << std::endl;
        std::cout << "list : " << B << std::endl;
        std::cout << "list : " << C << std::endl;

        
    }
    {
        std::cout << "\n" << WHITE_B << "FIRST TEST \n" << NC;
        Span First(3);
        try
        {
            First.addNumber(1);
            First.addNumber(9);
            First.addNumber(14);
            First.addNumber(25);
        }
        catch (std::exception &e)
        {
            std::cerr  << RED << e.what()  << NC << std::endl;
        }
        std::cout << "list : " << First << std::endl;
        std::cout << "Longest span : " << First.longestSpan() << std::endl;
        std::cout << "Shortest span : " << First.shortestSpan()<< std::endl;
    }
    {
        std::cout<< "\n" << WHITE_B << "SECOND TEST \n" << NC;
        try 
        {
            std::vector<int> bigVector(10000);
            Span myVector(10000);
            
            srand (time(NULL));
            std::generate( bigVector.begin(), bigVector.end(), std::rand );

            myVector.addNumber(bigVector.begin(), bigVector.end());
            std::cout <<  "Shortest Span " <<myVector.shortestSpan() << std::endl;
            std::cout << "Longest Span "<< myVector.longestSpan() << std::endl;
            // std::cout << "list : " << myVector << std::endl;

        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

