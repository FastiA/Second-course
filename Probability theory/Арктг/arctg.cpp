#include <iostream>
#include <math.h>
#include "header.h"
#include <glut.h> 

using namespace std;

const int ScreenW = 1920;
const int ScreenH = 1080;
double scale = 3.0;

typedef struct tagpoint
{
	double Ix;
	double Iy;
	double Lib;
}point;


int main(int argc, char* argv[]) 
{
	struct tagpoint point;
	int n = 1;
	int size = 100000;
	int* sizez = &size;
	double x = 0.0;
	double E = 0.001;
	cout << "Enter x: ";
	cin >> x;//Вводимо абсцису
	x = checkx(x);//Перевіряємо чи х підходить умовам
	double arctglib = atan (x);//Обраховуємо за допомогою математичної функції комп'ютерне значення х
	cout << "Using biblary function = " << arctglib << endl;
	double* arr = new double[size];
	row(arr, sizez, n, x, E);//Заповнюємо масив
	printArr(arr, size);//Виводимо масив
	
	point.Ix = x;
	point.Iy = sumaInMatrix(arr, size);//Обраховуємо і записуємо значення ординати
	point.Lib = arctglib;
	wreadXY(point.Ix, 'x', 1, 0);
	wreadXY(point.Iy, 'y', 1, 0);
	wreadXY(point.Lib, 'Y', 1, 0);
	delete[] arr;

	glutInit(&argc, argv);
	glutCreateWindow("Arctg");//Створення вікна із заданим ім'ям
	glutInitWindowSize(ScreenW, ScreenH);//Ширина та висота вікна
	glutInitWindowPosition(0, 0);//Положення вікна
	glutKeyboardFunc(keyboard);//Підключаємо клавіатуру
	glutDisplayFunc(display);
	glutMainLoop();

	return(0);
}

void display()
{
	glMatrixMode(GL_PROJECTION);//Тип матриці (проекційна)
	glLoadIdentity();//Загрузка одиничної матриці
	gluOrtho2D(0, ScreenW, 1, ScreenH);

	double xd = 0.0;
	double yd = 0.0;
	double yL = 0.0;

	xd = wreadXY(1, 'x', 0, 1);
	yd = wreadXY(1, 'y', 0, 1);
	yL = wreadXY(1, 'Y', 0, 1);
	double pohibka = fabs(yL - yd);
	cout << "Absolute pohibka: " << pohibka << endl;
	cout << "" << endl;
	cout << "X: " << xd << endl;
	cout << "Y: " << yd << endl;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	double xscale = ScreenW / scale;
	double yscale = ScreenH / scale;

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (float x = -1; x <= 1; x += 0.0001)
	{
		float y = rowDisplay(x);
		glVertex2f(x * xscale + ScreenW / 2, y * yscale + ScreenH / 2);
	}
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);		
	glVertex2f(-ScreenW, ScreenH / 2);
	glVertex2f(ScreenW, ScreenH / 2);
	glVertex2f(ScreenW / 2, -ScreenH);
	glVertex2f(ScreenW / 2, ScreenH);
	glEnd();
	glFlush();

	
	glPointSize(9);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);		
	glVertex2f(xd * xscale + ScreenW / 2, yd * yscale + ScreenH / 2);

	glEnd();
	glFlush();

}


