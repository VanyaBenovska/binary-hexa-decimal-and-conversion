// 03_JA1_04_Roxettes_ExOr_CHAR_arr_POINTERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<iomanip> 
#include <bitset>
//#include <chrono>
using namespace std;

void ExOr_chArr(char * fiveSigns_HexaNumber, char * exOrResult, const int & chArrSize)
{
	for (int i = 0; i < 5; i++)
	{
		exOrResult[i] = exOrResult[i] ^ fiveSigns_HexaNumber[i];
	}
}

void Copy_5signs_FirstTime(char * chArr_exOrResult, char * chArr_fiveSigns_HexaNumber, const int & chArrSize)
{
	for (int i = 0; i < 5; i++)
	{
		chArr_exOrResult[i] = chArr_fiveSigns_HexaNumber[i];
	}
}

void PrintCharArr(char * chArr, const int & chArr_size)
{
	//char * ptr = chArr;
	for (int i = 0; i < chArr_size - 1; i++)
	{
		cout << chArr[i];

		//cout << (char) chArr[i];
		//cout << static_cast<char>(chArr[i]);
		//cout << (*ptr);		
	}

	//chArr[strlen(chArr)] = '\0';
	//ptr[chArr_size - 1] = '\0';
	//while (*ptr != 0) cout << *ptr++;	

	//cout << chArr;

	cout << endl;
}

//static string fiveSigns_HexaNumber, strExOrResult;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	char * chArr_fiveSigns_HexaNumber = new char[6];
	char * chArr_exOrResult = new char[6];

	bool isFirstTime = true;
	char ch;
	cin >> ch;
	int k = 0;
	while (ch != '.')
	{
		if (k < 5)
		{
			chArr_fiveSigns_HexaNumber[k] = ch;
			k++;
		}
		else
		{
			k = 0;

			if (isFirstTime)
			{
				//copy first element
				Copy_5signs_FirstTime(chArr_exOrResult, chArr_fiveSigns_HexaNumber, 6);
				chArr_fiveSigns_HexaNumber[k] = ch;
				k++;
				isFirstTime = false;
			}
			else
			{
				ExOr_chArr(chArr_fiveSigns_HexaNumber, chArr_exOrResult, 6);
				//delete[] chArr_fiveSigns_HexaNumber;
				chArr_fiveSigns_HexaNumber[k] = ch;
				k++;
			}
		}
		cin >> ch;
	}
		 
	ExOr_chArr(chArr_fiveSigns_HexaNumber, chArr_exOrResult, 6);
	PrintCharArr(chArr_exOrResult, 6);

	delete[] chArr_fiveSigns_HexaNumber;
	delete[] chArr_exOrResult;

	return 0;
}


