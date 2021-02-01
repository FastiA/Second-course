#ifndef dk_line_h
#define dk_line_h
#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagFigure
{
	Point* A;
	Point* B;
	Point* C;
	Point* D;
}Figure;

Figure* createSquare(Point* A, Point* B, Point* C, Point* D);

void printSquare(Figure* aSquare);
void destroyLine(Figure* aFigure);
float lenghLine(Figure* aFigure);

#endif
