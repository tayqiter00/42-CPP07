/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:00:33 by qtay              #+#    #+#             */
/*   Updated: 2025/02/06 12:55:42 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/**
 * 1st param: address on an array
 * 2nd param: length of array
 * 3rd param: function that'll be called on each element in the array
 * Must work with any type of array.
 */
template <typename T>
void	iter(T *addr, size_t arrLen, void(*func)(T&))
{
	for (size_t i = 0; i < arrLen; i++)
		func(addr[i]); // must pass by reference so that no copying is done here
}

/**
 * Test function
 */
void	capitalizeFirst(std::string& arrElement)
{
	if (!arrElement.empty())
	{
		arrElement[0] = std::toupper(arrElement[0]);
	}
}

/**
 * Additional test functions to test if iter() works with an instantiated
 * function template.
 */
template <typename T>
void	printElement(T &arrElement)
{
    std::cout << arrElement << " ";
}

template <typename T>
void	incrementElement(T &arrElement)
{
	arrElement += 33;
}

#endif
