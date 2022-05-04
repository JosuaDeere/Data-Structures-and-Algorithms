#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void printMatrix(int* in_Matrix, int in_nRows, int in_nColumns);
int main()
{
	const int nRows = 5;
	const int nColumns = 5;
	int nColumnCounter = nColumns;
	int* nMatrix = new int[nRows*nColumns];
	bool bRowZeroMap[nRows] = { false };
	bool bColumnZeroMap[nColumns] = { false };
	
	//create seed 
	srand(time(NULL));

	//fill matrix
	for (size_t i = 0; i < nRows*nColumns; i++)
	{
		*nMatrix = rand() % 10;
		nMatrix++;
	}
	nMatrix -= nRows * nColumns;//return to first element
	printMatrix(nMatrix, nRows, nColumns);

	for (size_t i = 0; i < nColumns; i++)
	{
		for (size_t j = 0; j < nRows; j++)
		{
			if (*nMatrix == 0)
			{

				bColumnZeroMap[j] = true;
				bRowZeroMap[i] = true;
			}
			nMatrix++;
		}
	}
	nMatrix -= nRows * nColumns;
	
	int nPointerHelper = 0;
	int* TempMat = nMatrix;
	for (size_t j = 0; j < nColumns; j++)
	{
		if (bColumnZeroMap[j])
		{
			nPointerHelper = j;
			for (size_t i =0 ; i < nRows; i++ )
			{
				
				TempMat += nPointerHelper;
				*TempMat = 0;
				nPointerHelper = nRows;
			}
			TempMat = nMatrix;
			
		}
		
	}

	TempMat = nMatrix;
	cout << "\n";
	printMatrix(nMatrix, nRows, nColumns);
	for (size_t i = 0; i < nRows; i++)
	{
		if (bRowZeroMap[i])
		{
			nPointerHelper = i * nColumns;
			for (size_t j = 0; j < nColumns; j++)
			{
				
				TempMat += nPointerHelper;
				*TempMat = 0;
				nPointerHelper = 1;
			}
			TempMat = nMatrix;
		}
		
	}
	cout << "\n";
	printMatrix(nMatrix, nRows, nColumns);
	cin.get();
	nMatrix = nullptr;
	delete[] nMatrix;
}

void printMatrix(int* in_Matrix, int in_nRows, int in_nColumns)
{
	int nTempColumnCounter = in_nColumns;
	for (size_t i = 0; i < in_nRows * in_nColumns; i++)
	{
		
		cout << *in_Matrix;
		if (i == nTempColumnCounter - 1)
		{
			cout << "\n";
			nTempColumnCounter = nTempColumnCounter + in_nColumns;
		}

		in_Matrix++;
	}
	in_Matrix -= in_nRows * in_nColumns;//return to first element
}


