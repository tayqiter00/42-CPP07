/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:53:50 by qtay              #+#    #+#             */
/*   Updated: 2024/11/14 22:09:50 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/**
 * For copy and copy assignment, deep copies are required:
 * 		In both cases, modifying either the original array or its copy after
 * 		copying musn’t affect the other array.
 */
template <typename T>
class Array
{
	private:
		T		*_arrPtr;
		size_t	_arrSize;

	public:
		Array(void);
		Array(size_t n);
		Array(const Array &arr);
		Array	&operator=(const Array &arr);
		~Array(void);

		size_t	size(void) const;
		T	&operator[](size_t n);

		class IndexOutofBounds : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

/**
 * The parantheses after new T[0] automatically initializes it to zero for
 * example of T is of type <int>.
 */
template<typename T>
Array<T>::Array(void) : _arrPtr(new T[0]()), _arrSize(0)
{
	cout << "Array default constructor called" << endl;
}

/**
 * The parantheses after new T[n] automatically initializes it to zero for
 * example of T is of type <int>.
 */
template<typename T>
Array<T>::Array(size_t n) : _arrPtr(new T[n]()), _arrSize(n)
{
	cout << "Array parametrized constructor called" << endl;
}

template<typename T>
Array<T>::Array(const Array &arr)
	: _arrPtr(new T[arr.size()]), _arrSize(arr.size())
{
	for (size_t i = 0; i < arr.size(); i++)
		_arrPtr[i] = arr._arrPtr[i];
	cout << "Array copy constructor called" << endl;
}

/**
 * delete[] deallocates memory that was allocated for an array of objects
 */
template<typename T>
Array<T> &Array<T>::operator=(const Array &arr)
{
	if (this != &arr)
	{
		delete[] _arrPtr;
		_arrPtr = new T[arr._arrSize];
		_arrSize = arr._arrSize;
		for (size_t i = 0; i < arr._arrSize; i++)
			_arrPtr[i] = arr._arrPtr[i];
		cout << "Array copy assignment operator called" << endl;
	}

	return (*this);
}

template <typename T>
T	&Array<T>::operator[](size_t n)
{
	if (n >= _arrSize)
		throw Array<T>::IndexOutofBounds();
	return (_arrPtr[n]);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _arrPtr;
	cout << "Array default destructor called" << endl;
}

template<typename T>
size_t Array<T>::size(void) const
{
	return (_arrSize);
}

template <typename T>
char const*	Array<T>::IndexOutofBounds::what(void) const throw()
{
	return ("Array exception: index out of bounds");
}

#endif
