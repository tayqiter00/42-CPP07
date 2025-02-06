/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:01:09 by qtay              #+#    #+#             */
/*   Updated: 2025/02/06 12:39:15 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

/**
 * <dataType> must be given to the function pointers in iter() so that the
 * compiler knows how to instantiate them. This isn't needed for iter() as the
 * compiler can deduce from the array type passed to it (template argument
 * deduction).
 */
int	main()
{
	{
		int	intArr[] = {1, 2, 3, 4, 5};
		
		std::cout << "Before increment: ";
		::iter(intArr, 5, printElement<int>);
		std::cout << std::endl;

		::iter(intArr, 5, incrementElement<int>);
		std::cout << "After increment: ";
		::iter(intArr, 5, printElement<int>);
		std::cout << std::endl;
	}

	{
		std::string	strArr[] = {"alice", "bob", "charlie"};

		std::cout << "Before capitalizing first letter: ";
		::iter(strArr, 3, printElement<std::string>);
		std::cout << std::endl;

		::iter(strArr, 3, capitalizeFirst);
		std::cout << "After capitalizing first letter: ";
		::iter(strArr, 3, printElement<std::string>);
		std::cout << std::endl;
	}

	{
		std::string	strArr[] = {"alice", "bob", "charlie"};

		std::cout << "Before incrementing (str): ";
		::iter(strArr, 3, printElement<std::string>);
		std::cout << std::endl;

		::iter(strArr, 3, incrementElement<std::string>);
		std::cout << "After incrementing (str): ";
		::iter(strArr, 3, printElement<std::string>);
		std::cout << std::endl;
	}
}
