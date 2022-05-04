// RemoveDups.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "LinkedList.h";
using namespace std;
int main()
{
    LinkedList *myList=new LinkedList(1);
    LinkedList::Node* newNode = new LinkedList::Node();
    newNode->nData = 3;
    newNode->pNext = nullptr;

    myList->CreateNodeWithData(2);
    myList->addNode(newNode);//3
    myList->CreateNodeWithData(37);
    myList->CreateNodeWithData(38); 
    myList->CreateNodeWithData(39);
    myList->CreateNodeWithData(40);
    int nLength = myList->length();
    LinkedList::Node* pKthNode = new LinkedList::Node();
    pKthNode = myList->FindKthTolast(5);
    pKthNode;



    
   // myList->RemoveDups();
   // myList->RemoveNode(5);
   // myList->printNodes();
    cin.get();

    delete newNode;
    delete pKthNode;
}

