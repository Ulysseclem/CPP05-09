/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:58:58 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/13 16:25:50 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int size) : _size(size) 
{
    if (DEBUG)
        std::cout << "Span"  << GREEN << " Constructed" << NC << std::endl;
}

Span::Span(const Span& obj) : _size(obj._size), _container(obj._container)
{
    if (DEBUG)
        std::cout << "Span "  << GREEN <<  "copied" << NC << std::endl; 
    *this = obj;
}

Span &Span::operator=(const Span& obj)
{
    _size = obj._size;
    _container = obj._container;
    return *this;
}

Span::~Span()
{
     std::cout << "Span"  << RED << " destroyed" << NC << std::endl;     
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
    if (_container.size() < 2)
        throw SpanSizeException();

    int smallest = *std::min_element(_container.begin(), _container.end());
    int biggest = *std::max_element(_container.begin(), _container.end());
    
    return (biggest - smallest);
}

int	Span::shortestSpan()
{
    if (_container.size() < 2)
        throw SpanSizeException();

    std::vector<int> copyVector (_container.size());
    std::copy(_container.begin(), _container.end(), copyVector.begin());
    std::sort(copyVector.begin(), copyVector.end());
    int spanSize =*(copyVector.begin() + 1) - *copyVector.begin();
    for (std::vector<int>::iterator  i = copyVector.begin(); i != copyVector.end() -1; i++)
    {
        if (*(i + 1) - *i < spanSize)
            spanSize = *(i + 1) - *i;
    }
    return (spanSize);
}

// Getters
const std::vector<int>& Span::getContainer() const
{
    return _container;
}

//Overload
std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    for (std::vector<int>::const_iterator it = obj.getContainer().begin(); it != obj.getContainer().end(); it++)
        os << *it << " ";
    return os;
}

