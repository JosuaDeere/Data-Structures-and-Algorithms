// StringCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int nMap[256] = { 0 };
    string szMyString = "aabbccdfg";
	for (int i = 0; i < szMyString.length(); i++)
	{
		nMap[int(szMyString[i])]++;
	}
	return 0;
}

