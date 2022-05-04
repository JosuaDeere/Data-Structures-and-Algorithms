#pragma once
#define CAPACITY 5000
#include <string>
#include <iostream>
using namespace std;
class CHashTable
{
private:
	//par key value type
	struct Item
	{
		string Key;
		string Value;
	};
	// my array where i will save all my key-value items.
	Item** m_ppItems;
	unsigned int m_nSize;//hash size
	unsigned int m_nCount;//internal counter
	

public:
	CHashTable();
	~CHashTable();
	CHashTable(unsigned int in_nSize);
	CHashTable(Item** in_ppItems, unsigned int in_nSize);
	unsigned int hashFunction(string in_szValue);//function to return a "unique" index
	Item* createItem(string in_szKey, string in_szValue);
	void insertItem(Item* in_pIem);
	void insertItem(string in_szKey, string in_szValue);
	void Release();
	unsigned int length();
	string search(string in_szKey);
	void printS(string in_szKey);
	void printT();
};

