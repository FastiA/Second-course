#include <iostream>
#include <math.h>


#define n 3

using namespace std;

double epsilon(double, double); //Відносна похибка
double delta(double, double); //Абсолютна похибка

int main(void)
{
	setlocale(LC_ALL, "Russian");
	double xtrue, a, b, c, x[n], t[n] = { -0.707107, 0, 0.707107}, res = 0; //Виділеня пам'яті і запись коефіцієнтів
	cout << "Введіть параметр а: ";
	cin  >> a;
	cout << "Введіть межі інтегрування b и c" << endl; //Ввод межей інтегрування
	cout << "Нижня границя b = ";
	cin >> b;
	cout << "Верхня границя c = ";
	cin >> c;
	xtrue = 0,4388245731174946;//Точне значення
	cout << "Комп'ютерне значення: " << xtrue << endl;
	for (int i = 0; i < n; i++) //Обрахування точок х
	{ 
		x[i] = ((b+c)/2) + ((c-b)*t[i])/2;
	}
	for (int i = 0; i < n; i++) // Квадратурная формула Чебышева, 3 точки
	{
		double temp = (c - b) / n*atan(x[i]);
		res += temp;
	}
	cout << "Интеграл exp(" << a << "*x) Чебышева: " << res << endl; // Вывод погрешностей
	cout << "Абсолютная погрешность: " << delta(xtrue, res) << endl; // Вывод абсолютной погрешности
	cout << "Относительная погрешность: " << epsilon(xtrue, res) * 100 << "%" << endl; // Вывод относительной погрешности

	system("pause");

	return 0;

}

double epsilon(double xtrue, double xfalse)// Відносна похибка
{
	double epsilon;
	if (xfalse != 0)
	{
		epsilon = abs(xtrue - xfalse) / xtrue;
	}
	else epsilon = 0;
	return epsilon;
}

double delta(double xtrue, double xfalse)//Абсолютна похибка
{
	double delta = abs(xtrue - xfalse);
	return delta;
}
