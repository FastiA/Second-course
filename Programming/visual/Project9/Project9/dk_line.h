#ifndef dk_line_h
#define dk_line_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagLine
{
	Point* A;
	Point* B;
}Line;

// Init interface
Line* createLineAB(Point* A, Point* B);
//Line* createLineWithCoordinate(int xA, int yA, int xB, int yB);
void destroyLine(Line* aLine);

float lenghLine(Line* aLine);
void printLineAB(Line* aLine);
void printLineBC(Line* aLine);

#endif /* dk_line_h */#pragma once
