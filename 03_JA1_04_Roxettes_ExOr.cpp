// 03_JA1_04_Roxettes_ExOr.cpp : Defines the entry point for the console application.
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

void strExOr(string & fiveSigns_HexaNumber, string & exOrResult)
{
	//stringstream ss;
	////string s1 = "5f0066";
	//ss << exOrResult;
	//int value_exOrResult;
	//ss >> hex >> value_exOrResult;

	//stringstream ss2;
	////string s1 = "5f0066";
	//ss2 << fiveSigns_HexaNumber;
	//int value_fiveSigns_HexaNumber;
	//ss2 >> hex >> value_fiveSigns_HexaNumber;

	//string binaryNumber = bitset<8>(value_fiveSigns_HexaNumber).to_string(); //decimal to binary
	//string binaryExOrResult = bitset<8>(value_exOrResult).to_string(); //decimal to binary

	char chExOr[5];

	for (int i = 0; i < 5; i++ )
	{
		exOrResult[i] = fiveSigns_HexaNumber[i] ^ exOrResult[i];
	}
}

void PrintString(string & s)
{
	for (int i = 0; i < s.size(); i++)
	{
		cout << (char)s[i];
	}
	cout << endl;
}

//static string fiveSigns_HexaNumber, strExOrResult;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string fiveSigns_HexaNumber, strExOrResult;

	bool isFirstTime = true;
	char ch;
	cin >> ch;
	int k = 0;
	while (ch != '.')
	{
		if (k < 5)
		{
			fiveSigns_HexaNumber += ch;			
			k++;
		}
		else
		{
			k = 0;	
			if (isFirstTime)
			{	
				strExOrResult = fiveSigns_HexaNumber;
				fiveSigns_HexaNumber = "";
				fiveSigns_HexaNumber += ch;
				k++;
				isFirstTime = false;
			}
			else
			{				
				strExOr(fiveSigns_HexaNumber, strExOrResult);
				fiveSigns_HexaNumber = "";
				fiveSigns_HexaNumber += ch;
				k++;
			}
		}
		cin >> ch;
	}

	strExOr(fiveSigns_HexaNumber, strExOrResult);	
	PrintString(strExOrResult);
	
	return 0;
}

