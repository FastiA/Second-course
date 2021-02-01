#include <stdio.h>
#include "tool.h"

int main(int argc, const char* argv[]) {
	int row, col;

	printf("Wwedit row and col:");
	scanf_s("%i""%i", &row, &col);
	create_matrix(row, col);

	return 0;
}