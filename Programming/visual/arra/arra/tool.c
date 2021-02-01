#include "tool.h"
#include <stdlib.h>


void fillarray(int** matrix, int row, int col)
{
	if (NULL == row || NULL == col)
	{
		printf("Vu ne zadali matricu\n");
	}

	else
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				scnaf("Matr[i][j] = %d", &matrix[i][j]);
			}
	}
}

//void multiply(int multyplier, int **matrix, int row, int col)
//{
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < col; j++)
//		{
//			matrix[i][j] = matrix[i][j] * multyplier;
//		}
//}