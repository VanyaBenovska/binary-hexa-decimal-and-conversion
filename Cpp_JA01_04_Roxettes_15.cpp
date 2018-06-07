// Cpp_JA01_04_Roxettes_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

static char result[5];

int main()
{
	bool isNotADot = true;
	bool isFirstTime = true;
	char currentChar[5]{ 0 };
	while (isNotADot)
	{
		int i = 0;
		std::cin >> currentChar[i];	
		if (currentChar[i] == '.')
		{
			break;
		}
		i++;
		std::cin >> currentChar[i++];
		std::cin >> currentChar[i++];
		std::cin >> currentChar[i++];
		std::cin >> currentChar[i];
				
		if (isFirstTime)
		{
			for (int i = 0; i < 5; i++)
			{
				result[i] = currentChar[i];
			}	
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				result[i] ^= currentChar[i];
			}			
		}			

		isFirstTime = false;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout<<result[i];
	}
	std::cout << std::endl << std::endl;

	return 0;
}

