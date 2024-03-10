/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:58:58 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/10 18:00:38 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int size) : _size(size) 
{
    if (DEBUG)
        std::cout << "Span Constructed" << std::endl;
}

Span::Span(const Span& obj) : _size(obj._size)
{
    if (DEBUG)
        std::cout << "Span copied" << std::endl; 
    *this = obj;
}

Span &Span::operator=(const Span& obj)
{
    (void)obj;
    if (DEBUG)
        std::cout << "Span assigned" << std::endl; 
    return *this;
}

Span::~Span()
{
     std::cout << "Span destroyed" << std::endl;     
}

//Member function

void Span::addNumber(int nbr)
{
    if (_container.size() == _size)
        throw SpanSizeException();
    _container.push_back(nbr);
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    if (_container.size() == _size)
        throw SpanSizeException();
    _container.insert(_container.end(), begin, end);
}

int	Span::longestSpan()
{
    int smallest = 1000000;
    int biggest = 0;

    for (std::vector<int>::iterator  i = _container.begin(); i != _container.end(); i++)
    {
        if (*i < smallest)
            smallest = *i;
        if (*i > biggest)
            biggest = *i;
    }
    return (biggest - smallest);
}

int	Span::shortestSpan()
{
    int spanSize = 1000000;

    for (std::vector<int>::iterator j = _container.begin();  j != _container.end(); j++)
    {
        for (std::vector<int>::iterator  i = _container.begin(); i != _container.end(); i++)
        {
            if (*j - *i > -1 && i != j && spanSize > *j - *i)
                spanSize = *j - *i;
        }
    }
    return spanSize;
}
