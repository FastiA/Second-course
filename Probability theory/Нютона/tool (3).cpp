#include "tool.h"
#include <iostream>
#include <math.h>
#define fabs
using namespace std;


float* getArrX(float xNull, float h, int size)
{
	float* arr = new float[size];
	arr[0] = xNull;
	for (int i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + h;
	}
	return arr;
}

float* getArrY(float* arrX, int size)
{
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = atan(arrX[i]);
	}
	return arr;
}

void printArrX(float* arr, float size)
{
	cout << "#\t";
	for (int i = 0; i < size; i++)
	{
		cout << i << "\t";
	}

	cout << "\nx:\t";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << "\ny:\t";

	for (int i = 0; i < size; i++)
	{
		printf("%.4f\t", atan(arr[i]));
	}
}

float** tabRaznitsa(float* arrY, float size, int detn)
{
	int tSize = size;
	float** arrs = new float* [detn];
	for (int i = 0; i < detn - 1; i++)
	{
		if (i == 0)
		{
			arrs[i] = getdetArr(arrY, size, i);
		}
		else
		{
			arrs[i] = getdetArr(arrs[i - 1], size, i);
		}
	}
	return arrs;
}

float* getdetArr(float* arrY, int size, int i)
{
	float* arr = new float[size - i - 1];
	for (int j = 0; j < size - i; j++)
	{
		arr[j] = arrY[j + 1] - arrY[j];
	}
	return arr;
}

void printArrInArr(float** arr, int size, int n)
{
	cout << endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << "det" << i + 1 << "y" << "\t";
		for (int j = 0; j < size - i - 1; j++)
		{

			cout << fabs(arr[i][j]) << "\t";

		}
		cout << endl;
	}
}

float fact(int n)
{
	int steps = n;
	float result = 1;
	
	for (float i = 1; i < n ; i++) 
	{
		result = result * i;
	}
	return result;
}

float razn(float** raznitsaArr, int n)
{
	float result = 1;
	for (int i = 1; i < n - 1 ; i++) 
	{
		result = result * raznitsaArr[i][0];
	}
	return result;
}

float sum(float q, int n) 
{
	float result = 1;
	for (int i = 1; i < n; i++)
	{
		result = result * (q - i + 1);
	}
	return result;
}
float result(float* arrY, float** raznitsaArr, float q, int n)
{
	float summa = 0;
	float result = 0;

	float facto = fact(n);
	float sumo = sum(q,n);
	float razno = razn(raznitsaArr,n);
		
	summa = (sumo * razno) / facto ;
	result = arrY[0] + q * raznitsaArr[0][0] + summa;
	
	return result;
}