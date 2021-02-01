#include "dk_line.h"
#include <stdlib.h>
#include <math.h>
Point* copyPointWithPoint(Point* aPoint);

Point* copyPointWithPoint(Point* aPoint)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}

	return theResult;
}

Figure* createSquare(Point* A, Point* B, Point* C, Point* D)
{
	Figure* theResult = NULL;

	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		theResult = (Figure*)malloc(sizeof(Figure));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
			theResult->D = copyPointWithPoint(D);
		}
	}

	return theResult;
}



void printSquare(Figure* aFigure)
{
	if (NULL != aFigure)
	{
		printf("[Square]. A(%d,%d) B(%d,%d) C(%d,%d) D(%d,%d)\n",
			aFigure->A->x, aFigure->A->y,
			aFigure->B->x, aFigure->B->y,
			aFigure->C->x, aFigure->C->y,
			aFigure->D->x, aFigure->D->y);
	}
}

void destroyLine(Figure* aFigure)
{
	if (NULL != aFigure)
	{
		free(aFigure->A);
		free(aFigure->B);
		free(aFigure->C);
		free(aFigure->D);


		free(aFigure);
	}
}

float lenghLine(Figure* aFigure)
{
	float theResult = 0.0;

	if (NULL != aFigure)
	{
		float dX = (aFigure->A->x - aFigure->B->x);
		float dY = (aFigure->A->y - aFigure->B->y);
		theResult = sqrt(dX * dX + dY * dY);
	}

	return theResult;