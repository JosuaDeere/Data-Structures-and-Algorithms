// URLify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string cSpecialChar= "%20";
void sReplaceBS(string in_szMyString, int in_nTrueLenght);
int main()
{
	string szMyString ="My Name is Jose   ";
	sReplaceBS(szMyString, 15);
	//cout << szMyString;

}

void sReplaceBS(string in_szMyString, int in_nTrueLength)
{
	in_szMyString.erase(in_nTrueLength); //remove extra whitespaces at the end of the "true length"
	int nFinalSize, nSpaceCount = 0;

	//replace whitespaces with %20
	for (int i = 0; i < in_szMyString.length(); i++)
	{
		if (in_szMyString[i] == (char)32)//|| in_szMyString[i] == "\n" || in_szMyString[i] == "\t")
		{
			nSpaceCount++;
		}
	}
	nFinalSize = in_nTrueLength + nSpaceCount + nSpaceCount;
	
	string szTemp = in_szMyString;
	szTemp.resize(nFinalSize);
	for (int i = in_nTrueLength-1; i >= 0; i--)
	{
		if (in_szMyString[i] == (char)32)
		{
			szTemp[nFinalSize - 1] = '0';
			szTemp[nFinalSize - 2] = '2';
			szTemp[nFinalSize - 3] = '%';
			nFinalSize -= 3;
		}
		else
		{
			szTemp[nFinalSize - 1] = in_szMyString[i];
			nFinalSize--;
		}
	}
	in_szMyString = szTemp;
	cout << in_szMyString;
}