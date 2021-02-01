#include <stdio.h>
#include "dk_line.h"

int main(int argc, const char* argv[])
{
	Point A = { 0,0 };
	Point B = { 4,3 };
	Point C = { 10,3 };
	Point D = { 14,0 };

	Line* AB = createLine(&A, &B);
	Line* BC = createLine(&B, &C);
	Line* CD = createLine(&C, &D);
	Line* DA = createLine(&D, &A);

	printLineAB(AB);
	printf("The length of Line AB = %f\n", lenghLineAB(AB));
	printLineBC(BC);
	printf("The length of Line BC = %f\n", lenghLineBC(BC));
	printLineCD(CD);
	printf("The length of Line CD = %f\n", lenghLineCD(CD));
	printLineDA(DA);
	printf("The length of Line DA = %f\n", lenghLineDA(DA));

	printf("SquareABCD = %f\n", squareABCD());


	destroyLine(AB);

	return 0;
}