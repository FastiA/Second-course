#include "tool.h"
#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <math.h>

using namespace std;
const int windowW = 600;
const int windowH = 600;
double scale = 1.0;
double step = 0.0;
static double xPoint;
static double yPoint;

int main(int argc, char* argv[])
{
	int size = 10;
	float h = 0.1;
	cout << "Enter x(0):";
	float xNull = 0;
	cin >> xNull;
	cout << "Enter n:";
	int n;
	cin >> n;
	float* arrX = getArrX(xNull, h, size);
	printArrX(arrX, size);
	float* arrY = getArrY(arrX, size);
	float** raznitsaArr = tabRaznitsa(arrY, size, n);	//Розрахунок горизонтальної таблиці різниць
	printArrInArr(raznitsaArr, size, n);					//Cout горизонтальної таблиці різниць

	cout << "\n Enter x which you want to search :" << endl << "x:";
	float x;
	cin >> x;//Вводимо x
	float correctAtan = atan (x);
	float q = 0;
	q = (x - xNull) / h;
	cout << "q = " << q << endl;
	cout << "My interpolation = " << result(arrY, raznitsaArr, q, n) << endl;//Інтерполяція
	yPoint = result(arrY, raznitsaArr, q, n);
	xPoint = x;
	cout << "Lib interpolation = " << atan(x) << endl;//Бібліотечна інтерполяція
	cout << "Absolute mistage = " << fabs(correctAtan - result(arrY, raznitsaArr, q, n)) << endl;//Похибка
	cout << "Enter scale:";
	cin >> scale;
	glutInit(&argc, argv);
	glutCreateWindow("Atan"); //Створення вікна із заданим ім'ям
	glutInitWindowSize(windowW, windowH); //Ширина та висота вікна
	glutInitWindowPosition(0, 0); //Положення вікна
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void display()
{
	glMatrixMode(GL_PROJECTION);//Тип матриці (проекційна)
	glLoadIdentity();//Загрузка одиничної матриці
	gluOrtho2D(-windowW, windowW, -windowH, windowH);//glOrto(left, right, bottom, top, zNear, zFar); gluOrto2D(left, right, bottom, top);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); //Очищення буферу кольору
	float xscale = windowW / scale;
	float yscale = windowH / scale;

	glBegin(GL_LINE_STRIP); //Графік ф-ції
	glColor3f(1.0f, 0.0f, 0.0f);
	for (float x = -600; x <= 600; x += 0.001)
	{
		float y = atan(x);

		glVertex2f(x * xscale + step, y * yscale + step);
	}
	glEnd();
	glFlush();

	glBegin(GL_LINES);//Вісь x на y
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-windowW, 0);
	glVertex2f(windowW, 0);
	glVertex2f(0, -windowH);
	glVertex2f(0, windowH);
	glEnd();

	glFlush();

	glPointSize(4);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);//Колір точки
	glVertex2f(xPoint * xscale, yPoint * yscale);

	glEnd();
	glFlush();
}