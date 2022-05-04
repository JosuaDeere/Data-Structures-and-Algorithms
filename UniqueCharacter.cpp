// UniqueCharacter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	char szCurrent = NULL;  // temporal string charactert comparison.
//	string szMyString = "josuaaaaa";
//	int nPivot = 0;
//	bool bFinished = false;
//	while (nPivot < szMyString.length() && !bFinished )
//	{
//		szCurrent = szMyString[nPivot];
//		for (int i = nPivot+1; i < szMyString.length(); i++)
//		{
//			if (szCurrent == szMyString[i])
//			{
//				cout << "String :" + szMyString +" Not unique";
//				bFinished = true;
//				break;
//			}
//		}
//		nPivot++;
//	}
//	if (!bFinished)
//		cout << "String :" + szMyString + " has all its characters unique...";
//
//}

int main()
{
	string szMyString = "abccdefghi";
	bool baCharStatus[128] = { false };
	bool bUnique = true;
	if (szMyString.length() > 128)
		cout << "String: " + szMyString + " has repetead characters...";

	for (int i = 0; i < szMyString.length(); i++)
	{
		int nCharVal = szMyString[i];
		if (baCharStatus[nCharVal])
		{
			cout << "String: " + szMyString + " has repetead characters...";
			bUnique = false;
			break;
		}
		baCharStatus[nCharVal] = true;
	}
	if(bUnique)
	cout << "String: " + szMyString + " is unique...";
}