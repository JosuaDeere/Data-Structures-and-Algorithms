// CheckPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPermutation(string in_szFirst, string in_szSecond);
int main()
{
	string szMyStringFirst = "abcd";
	string szMyStringSecond = "dcba";
	if (isPermutation(szMyStringFirst, szMyStringSecond))
	{
		cout << "First string: " + szMyStringFirst + " is permutation of " + szMyStringSecond;
	}
	else
	{
		cout << "The strings " + szMyStringFirst + " and " + szMyStringSecond + " are not permutations of the other.";
	}
}

bool isPermutation(string in_szFirst, string in_szSecond)
{
	if (in_szFirst.length() != in_szSecond.length())// not equal length means they are not permutations at all.
		return false;

	sort(in_szFirst.begin(), in_szFirst.end());
	sort(in_szSecond.begin(), in_szSecond.end());
	if (in_szFirst == in_szSecond)
		return true;
	
	return false;
}