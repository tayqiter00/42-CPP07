/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:00:33 by qtay              #+#    #+#             */
/*   Updated: 2024/11/14 14:39:04 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *addr, size_t arrLen, void(*func)(T&))
{
	for (size_t i = 0; i < arrLen; i++)
		func(addr[i]);
}

/**
 * Additional functions to test if iter() works with an instantiated function
 * template.
 */
template <typename T>
void	printElement(T &arrElement)
{
    std::cout << arrElement << " ";
}

template <typename T>
void	incrementElement(T &arrElement)
{
	arrElement += 1;
}

template <typename T>
void	capitalizeFirst(std::string& arrElement)
{
	if (!arrElement.empty())
	{
		arrElement[0] = std::toupper(arrElement[0]);
	}
}

#endif
