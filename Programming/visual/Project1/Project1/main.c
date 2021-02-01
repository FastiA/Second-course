#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char* argv[])
{
	int row, col;
	int** matrix;
	//int(*arr)[row] = malloc(sizeof(int[row][col]));

	prinrf("Inscribe row and col");
	scnaf("%i %i", &row, &col);

	fillarray(matrix, row, col);

}

