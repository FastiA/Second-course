#ifndef dk_line_h
#define dk_line_h

#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagLine
{
	Point* A;
	Point* B;

}Line;

Line* createLine(Point* A, Point* B);
void destroyLine(Line* aLine);

float lenghLineAB(Line* aLine);
float lenghLineBC(Line* aLine);
float lenghLineCD(Line* aLine);
float lenghLineDA(Line* aLine);

void printLineAB(Line* aLine);
void printLineBC(Line* aLine);
void printLineCD(Line* aLine);
void printLineDA(Line* aLine);
float squareABCD();
#endif /* dk_line_h */#pragma once#pragma once
