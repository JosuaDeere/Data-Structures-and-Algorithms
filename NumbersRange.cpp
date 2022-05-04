// NumbersRange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    //this will hold my ranges, the key will be the first position and the value will be the last position from the range, if there is no range, value is empty.
    map<int, int> umValuesTable;

    vector<int> iaTestData { -6,-3,-2,0,3,4,5,7,9,10,11,14,15,17,18,19,20 };
    

    int nKeyElement = iaTestData[0];

    umValuesTable[nKeyElement] = NULL;

    //iterate through the elements in order to create the ranges
    for (int i = 0; i < iaTestData.size()-1; i++)
    {

        //if inbetween nbr diferences is 1, it means it can be added to a range.
        if (iaTestData[i] - iaTestData[i + 1] == -1)
        {
            umValuesTable[nKeyElement] = iaTestData[i+1];
        }
        else
        {
            //else my key element will change.
            nKeyElement = iaTestData[i + 1];
            umValuesTable[nKeyElement] = NULL;
        }
    }

    
    //print maP
    for (auto It : umValuesTable)
    {
        string szFinalString = to_string(It.first) + (It.second ? "-" + to_string(It.second) : "") + ",";
        cout << szFinalString;
        cout << endl;
    }


    cin.get();
}


