/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:15 by ulysse            #+#    #+#             */
/*   Updated: 2024/03/06 16:54:43 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Color.hpp"
#include <iostream>

template <typename T>
class Array
{
	private :
		T 				*_array;
		unsigned int 	_size;

	public :
	// Constructor
		Array() : _array(new T), _size(0) {
				std::cout << "Array " << GREEN_B << "Constructed" << NC << "\n"; }

		Array(unsigned int n) : _array(new T[n]), _size(n) {
			std::cout << "Array " << GREEN_B << "Constructed with N" << NC << "\n"; }

		Array(const Array& obj) : _array( new T[obj.size()] ), _size( obj.size() ) {
				for ( unsigned int i( 0 ); i < _size; i++ )
					_array[i] = obj._array[i];
			std::cout << "Array " << GREEN_B << "Constructed (copy)" << NC << "\n";		
		}
		
		Array &operator=(const Array &src)
		{
			if (_array != NULL)
				delete[] _array;
			_size = src.size();
			_array = new T [_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
			return (*this);
		}

		~Array()
		{
			if (_size != 0)
				delete[] _array;
			else
				delete _array;
			std::cout << "Array " << RED_B << "Destroyed" << NC << "\n";
		}

	//Exeption
		class IndexExeption : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

	//Getter
		T *getArray()
		{
			return _array;
		}

	//Members
		unsigned int size() const
		{
			return _size;
		}

	//Overload
		T &operator[](unsigned int ind) const
		{
			if (_array == NULL || ind >= _size)
				throw IndexExeption();
			return (_array[ind]);
		}
};

template <typename T>
const char *Array<T>::IndexExeption::what() const throw()
{ 
	return ("Error with the given index");
}

#endif 