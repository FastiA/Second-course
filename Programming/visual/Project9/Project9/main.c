#include <stdio.h>
#include "dk_line.h"

int main(int argc, const char* argv[])
{
	Point A = { 2,3 };
	Point B = { 4,6 };
	Point C = { 4,7 };
	Point D = { 3,8 };

	Line* AB = createLine(&A, &B);
	printf("The length of Line AB = %f\n", lenghLine(AB));
	Line* BC = createLine(&B, &C);
	printf("The length of Line BC = %f\n", lenghLine(BC));
	Line* CD = createLine(&C, &D);
	Line* DA = createLine(&D, &A);
	//Line* CD = createLineWithCoordinate(0, 1, 2, 3);
	//Line* AB = createLineWithCoordinate(4, 5, 6, 7);
	printLineAB(AB);
	printLineBC(BC);
	//printLine(CD);
	//printLine(DA);


	//CD->A->y = 34;
	//printLine(CD);

	//A.x = 10;
	//printLine(AB);

	//AB->A->x = 11;
	//printLine(AB);

	//printf("The length of Line AB = %f\n", lenghLine(AB));

	destroyLine(AB);
	
	return 0;
}