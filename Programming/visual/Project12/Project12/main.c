#include <stdio.h>
#include "dk_line.h"

int main(int argc, const char* argv[])
{
	Point A = { 0,0 };
	Point B = { 2,0 };
	Point C = { 0,2 };
	Point D = { 2,0 };

	Figure* ABCD = createSquare(&A, &B, &C, &D);
	printSquare(ABCD);
	printf("The length of Line AB = %f\n", lenghLine(AB));

	return 0;
}