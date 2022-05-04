#include "CHashTable.h"


CHashTable::CHashTable()
{
	m_ppItems = nullptr;
	m_nCount = 0;
	m_nSize = CAPACITY;

}

CHashTable::CHashTable(unsigned int in_nSize)
{
	m_ppItems = new Item*[in_nSize];

	for (int i = 0; i < in_nSize; i++)
	{
		m_ppItems[i] = new Item();
	}
	m_nCount = 0;
	m_nSize = in_nSize;
}
CHashTable::CHashTable(CHashTable::Item** in_ppNode, unsigned int in_nSize)  
{
	m_nSize = in_nSize;
	m_ppItems = in_ppNode;
	m_nCount = 0;
}

CHashTable::~CHashTable()
{
	Release();
}
unsigned int CHashTable::hashFunction(string in_szValue)
{
	unsigned int uiIndex = 0;
	for (size_t i = 0; in_szValue[i] ; i++)
	{
		uiIndex += in_szValue[i];
	}
	return uiIndex % m_nSize;
}

CHashTable::Item* CHashTable::createItem(string in_szKey, string in_szValue)
{
	Item* pNewItem = new Item();
	pNewItem->Key = in_szKey;
	pNewItem->Value = in_szValue;
	return pNewItem;
}

void CHashTable::Release()
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		delete[] m_ppItems[i];
	}
	delete[] m_ppItems;
	m_ppItems = nullptr;
	m_nSize = 0;
	m_nCount = 0;
}

void CHashTable::insertItem(Item* in_pItem)
{
	return;
}

void CHashTable::insertItem(string in_szKey, string in_szValue)
{
	//create item based on key-value 
	//compute index
	//check if the index is already occupied or not, by comparing the key
		//if it is not occupied, we can directly insert it into index
		//else is a collision, we need to handle it
	unsigned int uiIndex = hashFunction(in_szKey);// get index
	Item* pNewItem = createItem(in_szKey, in_szValue);// create item
	Item* pCurrentItem = m_ppItems[uiIndex];//get current item in index

	//if it is null
	if (pCurrentItem->Key =="")
	{
		//check if table is full
		if (m_nCount == m_nSize)
		{
			//table is full
			delete pNewItem;
			cout << "Hashtable is full";
			return;
		}
		else
		{
			//insert directly, since the its a new index
			*m_ppItems[uiIndex] = *pNewItem;
			m_nCount++;
		}
	}
	else
	{
		//compare if the keys are equal, this mean we want to update the value
		if (!strcmp(pCurrentItem->Key.c_str(), in_szKey.c_str()))
		{
			//they are equal
			m_ppItems[uiIndex]->Value = in_szValue;
			return;
		}
		else
		{
			//collision must be handled
			return;
		}
	}
	
}

unsigned int CHashTable::length()
{
	return m_nCount;
}

string CHashTable::search(string in_szKey)
{
	unsigned int uiIndex = hashFunction(in_szKey);
	Item* pNewItem = m_ppItems[uiIndex];

	if (!pNewItem)
	{
		return "";
	}
	else
	{
		return pNewItem->Value;
	}
}

void CHashTable::printS(string in_szKey)
{
	string szValue = search(in_szKey);
	if (szValue.empty())
	{
		cout << "Key: " + in_szKey << " does not exists." << endl;
	}
	else
	{
		cout << "Key: " + in_szKey << " Value: "<<szValue << endl;
	}
}
void CHashTable::printT()
{
	for (int i = 0; i < m_nSize; i++)
	{
		if(m_ppItems[i]->Key != "")
		cout << "Index: " + to_string(i) << " Key: " + m_ppItems[i]->Key << " Value: " + m_ppItems[i]->Value << endl;
	}
}