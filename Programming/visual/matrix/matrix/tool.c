#include <stdio.h>

int ** multiply(int multyplier, int **matrix, int row, int col)
{
	int ** result = create_matrix(row, col);

	for (int i = 0; i < row; i ++)
		for (int j = 0; j < col; j ++)
		result[i][j] = matrix[i][j] * multyplier;

	return result;
}

int create_matrix(int row, int col)
{
	int** matrix;
	int i, j;
	printf("Vvedit matrizu 4x4 :\n");
	
	while (i < 4)
	{
		while (j < 4)
		{
			printf("mat[%i][%i] =", i + 1, j + 1);
			scanf_s("%i", &matrix[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	printf("\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%i ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");

}