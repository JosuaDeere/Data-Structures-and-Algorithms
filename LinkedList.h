#pragma once

#ifdef LinkedList_EXPORTS
#define LinkedList_API __declspec(dllexport)
#else
#define LinkedList_API __declspec(dllimport)
#endif
#include <iostream>
using namespace std;

class LinkedList
{
public:
	struct Node
	{
		int nData;
		Node* pNext;
	};
public:
	Node* m_pNode;

	LinkedList();
	LinkedList(int in_nData);
	LinkedList(Node* in_pNode);
	~LinkedList();
	void CreateNodeWithData(int in_nData);//init node with data				 
	void addNode(Node* in_pNode); //create node with given data;
	void printNodes();
	void RemoveNode(int in_nData);
	void RemoveDups();
	void ReleaseNodePointer(Node* in_pNode);
	int length();
	Node* FindKthTolast(int in_nIndex);
};

LinkedList::LinkedList()
{
	m_pNode = new Node();
	m_pNode->nData = 0;
	m_pNode->pNext = nullptr;
}
LinkedList::LinkedList(int in_nData)
{
	m_pNode = new Node();
	m_pNode->nData = in_nData;
	m_pNode->pNext = nullptr;
}
LinkedList::LinkedList(Node* in_pNode)
{
	m_pNode->nData = in_pNode->nData;
	m_pNode->pNext = in_pNode->pNext;
}
LinkedList::~LinkedList()
{
	ReleaseNodePointer(m_pNode);
}


LinkedList::Node* LinkedList::FindKthTolast(int in_nIndex)
{
	//get length
	int nLength = 1;
	Node* pTemp = m_pNode;
	if (pTemp == nullptr)
	{
		cout << "List is empty";
		return NULL;
	}
	while (pTemp->pNext != nullptr)
	{
		nLength++;
		pTemp = pTemp->pNext;
	}


	if (in_nIndex >= nLength || in_nIndex < 0)
	{
		cout << "index out of range";
		return nullptr;
	}
	else if (in_nIndex == (nLength - 1))
	{
		return m_pNode;
	}
	pTemp = m_pNode->pNext;
	for (size_t i = (nLength - 2); i >= 0; i--)
	{

		if (i == in_nIndex)
		{
			return pTemp;
		}
		else
		{
			//if(pTemp->pNext != nullptr)
			pTemp = pTemp->pNext;
		}

	}


}
void LinkedList::CreateNodeWithData(int in_nData)
{
	Node* newNode = new Node();
	Node* pTempNode = m_pNode;
	if (m_pNode == nullptr)
	{
		m_pNode->nData = in_nData;
		m_pNode->pNext = nullptr;
	}
	else
	{
		newNode->nData = in_nData;
		newNode->pNext = nullptr;

		while (pTempNode->pNext != nullptr)
		{
			pTempNode = pTempNode->pNext;
		}
		pTempNode->pNext = newNode;
	}
	ReleaseNodePointer(pTempNode);

}

//create node with given data;
void  LinkedList::addNode(Node* in_pNode)
{
	CreateNodeWithData(in_pNode->nData);
}

void LinkedList::printNodes()
{
	Node* tempNode = m_pNode;
	while (tempNode->pNext != nullptr)
	{
		cout << tempNode->nData << "\n";
		tempNode = tempNode->pNext;
	}
	cout << tempNode->nData << "\n";
	ReleaseNodePointer(tempNode);
}


void LinkedList::RemoveNode(int in_nData)
{
	if (m_pNode == nullptr)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node* tempNode = m_pNode;
		while (tempNode->pNext != nullptr)
		{
			// if data match
			if (tempNode->nData == in_nData)
			{
				//my actual node will have the values of my next node
				tempNode->nData = tempNode->pNext->nData;
				tempNode->pNext = tempNode->pNext->pNext;
				break;
			}
			//if its the last item
			if (tempNode->pNext->pNext == nullptr)
			{
				//actual will point to null
				tempNode->pNext = nullptr;
			}
			else
			{
				tempNode = tempNode->pNext;
			}

		}
		ReleaseNodePointer(tempNode);
	}
}

void LinkedList::RemoveDups()
{

	Node* pCurrent = m_pNode;
	Node* pTempNode = pCurrent->pNext;
	if (m_pNode == nullptr || m_pNode->pNext == nullptr)
	{
		cout << "List only contains 1 item or its empty\n";
	}
	else
	{

		while (pCurrent->pNext != nullptr)
		{
			while (pTempNode->pNext != nullptr)
			{
				if (pCurrent->nData == pTempNode->nData)
				{
					pTempNode->nData = pTempNode->pNext->nData;
					pTempNode->pNext = pTempNode->pNext->pNext;

				}
				else
				{
					pTempNode = pTempNode->pNext;
				}

			}
			if (pCurrent->nData == pTempNode->nData)
			{
				pCurrent->nData = pCurrent->pNext->nData;
				pCurrent->pNext = pCurrent->pNext->pNext;
			}
			else
			{
				pCurrent = pCurrent->pNext;
				pTempNode = pCurrent->pNext;
			}

		}


	}
}

void LinkedList::ReleaseNodePointer(Node* in_pNode)
{
	in_pNode = nullptr;
	delete in_pNode;
}

int LinkedList::length()
{
	int nTemp = 1;
	Node* pTemp = m_pNode;

	if (pTemp == nullptr)
	{
		return 0;
	}
	while (pTemp->pNext != nullptr)
	{
		nTemp++;
		pTemp = pTemp->pNext;
	}
	return nTemp;
}

