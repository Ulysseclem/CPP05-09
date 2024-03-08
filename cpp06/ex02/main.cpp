/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:33:55 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/08 12:36:23 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>     
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base * generate(void)
{
    srand(time(NULL));
   
    switch (rand()%3)
    {
    case 0:
        return (new A);
    case 1:
        return (new B);
    case 2:
        return (new C);
    default:
        break;
    };
    std::cout << "Issue with Rand" << std::endl;
    return NULL;
}
    
void identify(Base* p)
{    
    if (dynamic_cast<A *>(p)) // renvoi 1 si le cast marche
        std::cout << "this is A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "this is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "this is C" << std::endl;
    else
        std::cout << "prout" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A& test = dynamic_cast<A &>(p);
        std::cout << "this is A (caught)" <<std::endl;
        (void)test; 
    }
    catch (std::exception &e){}
    try 
    {
        B& test = dynamic_cast<B &>(p);
        std::cout << "this is B (caught)" <<std::endl;
        (void)test; 
    }
    catch (std::exception &e){}
    try 
    {
        C& test = dynamic_cast<C &>(p);
        std::cout << "this is C (caught)" <<std::endl;
        (void)test; 
    }
    catch (std::exception &e){}
    
}

int main()
{
    Base * test = generate();
    identify(test);
    identify(*test);
}   