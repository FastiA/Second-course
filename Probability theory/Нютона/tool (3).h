#ifndef tool_h
#define tool_h
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
float* getArrX(float xNull, float h, int size);
float* getArrY(float* arrX, int size);
void printArrX(float* arr, float size);
float** tabRaznitsa(float* arrY, float size, int detn);
float* getdetArr(float* arrY, int size, int i);
void printArrInArr(float** arr, int size, int n);
float result(float* arrY, float** raznitsaArr, float q, int n);
void display();
float razn(float** raznitsaArr, int n);
float fact(int n);
float sum(float q, int n);
#endif tool_h
