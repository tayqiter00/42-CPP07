/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:35:44 by qtay              #+#    #+#             */
/*   Updated: 2025/02/06 12:24:32 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/**
 * Note: 'typename' keyword can also be replaced by the keyword 'class'
 * Templates are expanded at compile time after type checking
 */
template <typename T>
void swap(T &x, T &y)
{
	T	temp = x;
	
	x = y;
	y = temp;
}

template <typename T>
T min(T x, T y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T>
T max(T x, T y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif
