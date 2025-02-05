/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:00 by qtay              #+#    #+#             */
/*   Updated: 2024/11/14 18:02:40 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int	main()
{
	cout << "[ TEST 1: DEFAULT CONSTRUCTOR ]" << endl;
	try
	{
		Array<int> arr1;
		cout << "arr1 size: " << arr1.size() << endl;
	}
	catch(const std::exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	cout << endl;
	
	cout << "[ TEST 2: PARAMETERIZED CONSTRUCTOR ]" << endl;
	try
	{
		Array<int> arr2(5);
		cout << "arr2 size: " << arr2.size() << endl;
	}
	catch(const std::exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	cout << endl;
	
	cout << "[ TEST 3: COPY CONSTRUCTOR & INDEXING]" << endl;
	try
	{
		Array<int> arr3(5);
		for (size_t i = 0; i < arr3.size(); i++)
			arr3[i] = static_cast<int>(i * 3);
		Array<int> temp(arr3); // temp copies from arr3
		cout << "arr3: ";
		for (size_t i = 0; i < arr3.size(); i++)
			cout << arr3[i] << " ";
		cout << endl;
		cout << "temp: ";
		for (size_t i = 0; i < temp.size(); i++)
			cout << temp[i] << " ";
		cout << endl;
		cout << "Modifying temp should not affect arr3: " << endl;
		for (size_t i = 0; i < temp.size(); i++)
			temp[i] = 0;
		cout << "arr3: ";
		for (size_t i = 0; i < arr3.size(); i++)
			cout << arr3[i] << " ";
		cout << endl;
		cout << "temp: ";
		for (size_t i = 0; i < temp.size(); i++)
			cout << temp[i] << " ";
		cout << endl;
	}
	catch(const std::exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	cout << endl;

	cout << "[ TEST 4: COPY ASSIGNMENT OPERATOR ]" << endl;
	try
	{
		Array<int> arr4(5);
		Array<int> temp2(3);
		for (size_t i = 0; i < arr4.size(); i++)
			arr4[i] = i + 1;
		cout << "temp 2 array size before assignment is " << temp2.size() << endl;
		temp2 = arr4;
		cout << "temp 2 array size after assignment is " << temp2.size() << endl;
		cout << "Modifying temp2 should not affect arr4: " << endl;
		for (size_t i = 0; i < temp2.size(); i++)
			temp2[i] = 0;
		cout << "arr4: ";
		for (size_t i = 0; i < arr4.size(); i++)
			cout << arr4[i] << " ";
		cout << endl;
		cout << "temp2: ";
		for (size_t i = 0; i < temp2.size(); i++)
			cout << temp2[i] << " ";
		cout << endl;
	}
	catch(const std::exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	cout << endl;

	cout << "[ TEST 5: INDEXING OUT OF BOUNDS ]" << endl;
	try
	{
		Array<int> arr5(5);
		cout << arr5[5] << endl;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;

	cout << "[ TEST 6: SIMPLE TEST WITH STRINGS ]" << endl;
	try
	{
		Array<std::string> arr6(3);
		arr6[0] = "This";
		arr6[1] = "is";
		arr6[2] = "CPP07";
		for (size_t i = 0; i < 3; i++)
		{
			cout << arr6[i] << " ";
		}
		cout << endl;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

}
