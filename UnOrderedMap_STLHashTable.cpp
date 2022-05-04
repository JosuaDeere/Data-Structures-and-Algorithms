// UnOrderedMap_STLHashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int main()
{
    unordered_map<string, list<string>> MyHashTable;
    list<string> lMayansUniqueUnit = { "Plumed Archer","Eagle Warrior", "Obsidian Arrows" };
    list<string> lTurksUniqueUnit = { "Janissary", "Canoneer", "Bombard canon" };
    list<string> lAztectUniqueUnit = { "Jaguar Warrior" };

    MyHashTable["Mayans"] = lMayansUniqueUnit;
    MyHashTable["Turks"] = lTurksUniqueUnit;
    MyHashTable.insert(pair<string, list<string>>("Aztecs", lAztectUniqueUnit));

    for(auto item : MyHashTable)
    {
        cout << "Key is: " + item.first;
        for (auto unique : item.second)
            cout << " " + unique + ", ";
        cout << endl;

    }
    std::cout << "Hello World!\n";
    cin.get();
}
