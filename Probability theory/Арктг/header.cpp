#include <iostream>
#include "header.h"
#include <math.h>
#include<glut.h>

using namespace std;

void row(double* arr, int* size, int n, double x, double pohibka)
{
	double summa = 0.0;
	double fix = 1.0;
	int i = 0;
	do {
		double steps = step(n, x);
		double plusminus = plusMinus(n);
		double znam = znamen(n);
		summa = (plusminus * steps) / znam;
		double temps = summa;
		fix = fabs(temps);
		
		if (fix > pohibka)
		{
			arr[i] = summa;
			i++;
			n++;
			*size = n;
		}
		else
		{
			*size = *size - 1;
			return;
		}

	} while (fix > pohibka);
}

double step(int n, double x)
{
	int steps = 0;
	steps = (2 * n - 1);
	double temp = x;

	for (int i = 1; i < steps; i++)
	{
		temp = temp * x;
	}
	return temp;
}

double plusMinus(int n)
{
	if ((n - 1) % 2 == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

double znamen(int n)
{
	double f;
	f = (2 * n - 1);

	return f;

}

void printArr(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i + 1 << "]" << arr[i] << endl;
	}
}

double sumaInMatrix(double* arr, int size)
{
	double finish = 0.0;
	for (int i = 0; i < size; i++)
	{
		finish += arr[i];
	}
	cout << "Using my function = " << finish << endl;
	return finish;
}

double wreadXY(double xy, char zmin, int write, int read)
{
	static double x, y, yl;
	if (write == 1 && read == 0)
	{
		if (zmin == 'x')
		{
			x = xy;
		}
		if (zmin == 'y')
		{
			y = xy;
		}
		if (zmin == 'Y')
		{
			yl = xy;
		}
	}
	if (write == 0 && read == 1)
	{
		if (zmin == 'x')
		{
			return x;
		}
		if (zmin == 'y')
		{
			return y;
		}
		if (zmin == 'Y')
		{
			return yl;
		}
	}
}


double rowDisplay(double x)
{
	double summa = 0.0;
	double fix = 1.0;
	int i = 0;
	float E = 0.001;
	int n = 1;
	double finish = 0;
	do {
		double steps = step(n, x);
		double plusminus = plusMinus(n);
		double znam = znamen(n);
		summa = (plusminus * steps) / znam;
		double temps = summa;
		fix = fabs(temps);
		if (fix > E)
		{
			i++;
			n++;
			finish = finish + summa;
		}
		else
		{
			return finish;
		}

	} while (fix > E);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27: 
		exit(0);
		break;
	}
}

double checkx(double x)
{
	if (x > 1 || x < -1)
	{
		do 
		{
			cout << "Write new x: ";
			cin >> x;
		} while (x > 1 || x < -1);
	}
	return x;
}