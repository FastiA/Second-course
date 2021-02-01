#include "dk_line.h"
#include <stdlib.h>
#include <math.h>

Point* copyPointWithPoint(Point* aPoint);

Line* createLine(Point* A, Point* B)
{
	Line* theResult = NULL;

	if (NULL != A && NULL != B)
	{
		theResult = (Line*)malloc(sizeof(Line));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
		}
	}

	return theResult;
}

void printLineAB(Line* aLine)
{
	if (NULL != aLine)
	{
		printf("[Line]. A(%d,%d) - B(%d,%d)\n",
			aLine->A->x, aLine->A->y,
			aLine->B->x, aLine->B->y);
	}
}

void printLineBC(Line* aLine)
{
	if (NULL != aLine)
	{
		printf("[Line]. B(%d,%d) - C(%d,%d)\n",
			aLine->A->x, aLine->A->y,
			aLine->B->x, aLine->B->y);
	}
}

void printLineCD(Line* aLine)
{
	if (NULL != aLine)
	{
		printf("[Line]. C(%d,%d) - D(%d,%d)\n",
			aLine->A->x, aLine->A->y,
			aLine->B->x, aLine->B->y);
	}
}

void printLineDA(Line* aLine)
{
	if (NULL != aLine)
	{
		printf("[Line]. D(%d,%d) - A(%d,%d)\n",
			aLine->A->x, aLine->A->y,
			aLine->B->x, aLine->B->y);
	}
}

void printLineABCD(Line* aLine)
{
	if (NULL != aLine)
	{
		printf("[Line]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d)\n",
			aLine->A->x, aLine->A->y,
			aLine->B->x, aLine->B->y);
			
	}
}

float lenghLineAB(Line* aLine)
{
	float theResult = 0.0;

	if (NULL != aLine)
	{
		float dX = (aLine->B->x - aLine->A->x);
		float dY = (aLine->B->y - aLine->A->y);
		theResult = sqrt(dX * dX + dY * dY);
	}

	return theResult;
}

float lenghLineBC(Line* aLine)
{
	float theResult = 0.0;

	if (NULL != aLine)
	{
		float dX = (aLine->B->x - aLine->A->x);
		float dY = (aLine->B->y - aLine->A->y);
		theResult = sqrt(dX * dX + dY * dY);
	}

	return theResult;
}

float lenghLineCD(Line* aLine)
{
	float theResult = 0.0;

	if (NULL != aLine)
	{
		float dX = (aLine->B->x - aLine->A->x);
		float dY = (aLine->B->y - aLine->A->y);
		theResult = sqrt(dX * dX + dY * dY);
	}

	return theResult;
}

float lenghLineDA(Line* aLine)
{
	float theResult = 0.0;

	if (NULL != aLine)
	{
		float dX = (aLine->B->x - aLine->A->x);
		float dY = (aLine->B->y - aLine->A->y);
		theResult = sqrt(dX * dX + dY * dY);
	}

	return theResult;
}

float squareABCD()
{
	float a = 0, b = 0, c = 0, d = 0;
	float lenghLineAB = a;
	float lenghLineBC = b;
	float lenghLineCD = c;
	float lenghLineDA = d;

	float theResult = 0.0;

	theResult = 1 / 4 * (sqrt((b + d) * (b + d) * (d - b + 2 * a) * (b - d + 2 * a)));

	return theResult;
}

void destroyLine(Line* aLine)
{
	if (NULL != aLine)
	{
		free(aLine->A);
		free(aLine->B);

		free(aLine);
	}
}

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
