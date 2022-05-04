// hashtable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CHashTable.h"
int main()
{
    CHashTable* myTable = new CHashTable(CAPACITY);

    myTable->insertItem("1", "first address");
    myTable->insertItem("2", "second address");
   myTable->insertItem("3", "tres");
    myTable->insertItem("4", "cuatro");
    myTable->insertItem("5", "cinco");
    myTable->insertItem("6", "gugu");
    myTable->insertItem("7", "chato");
    myTable->insertItem("8", "pugsina");
    myTable->insertItem("9", "rayita");
    myTable->insertItem("10", "teclado");
    myTable->printS("2");
    myTable->printT();
    cin.get();
    // falta manipular las colisiones, hay de 2 o mejorar la hasfunction para realmente generar claves unicas *cryptografia, 
    //o hascer un bucket overfloww, en donde en cada index existira una lista donde iremos guardando las colisiones.
    // seria algo parecideo a una hash table de listas.
}

