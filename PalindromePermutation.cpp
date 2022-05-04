// PalindromePermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
bool isPalindrome(string in_szMyString);
void swap(char* in_cA, char* in_cB);
void permute(string in_szMyString, int in_nStart);
int main()
{
	
	permute("abba", 0);
}

bool isPalindrome(string in_szMyString)
{
	for (int i = 0; i < in_szMyString.length(); i++)
	{
		if (in_szMyString[i] == (char)32)
		{
			in_szMyString.erase(i, 1);
		}
	}
	for (int i = 1; i <= in_szMyString.length()/2; i++)
	{
		if (in_szMyString[i-1] == in_szMyString[in_szMyString.length() - i])
			continue;
		else
			return false;
	}
	return true;
}
void swap(char* in_cA, char* in_cB)
{
	char temp = *in_cA;
	*in_cA = *in_cB;
	*in_cB = temp;
}
void permute(string in_szMyString, int in_nStart)
{
	int nStringLength = in_szMyString.length() - 1;
	if (nStringLength == in_nStart)
	{
		cout << "\n" + in_szMyString + " ";
		string szResult = isPalindrome(in_szMyString) ? "true" : "False";
		cout << szResult;
	}
		
	else
		for (int i = in_nStart; i <= nStringLength; i++)
		{
			swap(in_szMyString[in_nStart], in_szMyString[i]);
			permute(in_szMyString, in_nStart + 1);
		}
}
		
