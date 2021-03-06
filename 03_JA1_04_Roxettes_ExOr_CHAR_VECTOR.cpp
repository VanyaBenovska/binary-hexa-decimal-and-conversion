// 03_JA1_04_Roxettes_ExOr_CHAR_VECTOR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<cmath>   
#include<iomanip>    
#include<string>
#include<climits>
#include<vector>
#include<sstream>
#include <bitset>
//#include <chrono>
using namespace std;

void vExOr_ch(vector<char> & fiveSigns_HexaNumber, vector<char> & exOrResult)
{
	for (int i = 0; i < 5; i++)
	{
		exOrResult[i] = exOrResult[i] ^ fiveSigns_HexaNumber[i];
	}
}

void Copy_5signs_FirstTime(char chArr_exOrResult[], char chArr_fiveSigns_HexaNumber[], int chArrSize)
{
	for (int i = 0; i < 5; i++)
	{
		chArr_exOrResult[i] = chArr_fiveSigns_HexaNumber[i];
	}
}

void PrintV(vector<char> & v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}	
	cout << endl;
}

//static string fiveSigns_HexaNumber, strExOrResult;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	//char chArr_fiveSigns_HexaNumber[6];
	//char chArr_exOrResult[6];
	vector<char> chv_fiveSigns_HexaNumber;
	vector<char> chv_exOrResult;

	bool isFirstTime = true;
	char ch;
	cin >> ch;
	int k = 0;
	while (ch != '.')
	{
		if (k < 5)
		{
			chv_fiveSigns_HexaNumber.push_back(ch);
			k++;
		}
		else
		{
			k = 0;

			if (isFirstTime)
			{
				//copy first element
				chv_exOrResult = chv_fiveSigns_HexaNumber;
				//Copy_5signs_FirstTime(chArr_exOrResult, chArr_fiveSigns_HexaNumber, 6);
				chv_fiveSigns_HexaNumber.clear();
				chv_fiveSigns_HexaNumber.push_back(ch);
				k++;
				isFirstTime = false;
			}
			else
			{
				vExOr_ch(chv_fiveSigns_HexaNumber, chv_exOrResult);
				chv_fiveSigns_HexaNumber.clear();
				chv_fiveSigns_HexaNumber.push_back(ch);
				k++;
			}
		}

		cin >> ch;
	}

	vExOr_ch(chv_fiveSigns_HexaNumber, chv_exOrResult);
	PrintV(chv_exOrResult);

	return 0;
}

