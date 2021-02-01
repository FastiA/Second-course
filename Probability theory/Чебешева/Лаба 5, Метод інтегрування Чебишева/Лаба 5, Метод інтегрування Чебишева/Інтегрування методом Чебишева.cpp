#include <iostream>
#include <math.h>


#define n 3

using namespace std;

double epsilon(double, double); //³������ �������
double delta(double, double); //��������� �������

int main(void)
{
	setlocale(LC_ALL, "Russian");
	double xtrue, a, b, c, x[n], t[n] = { -0.707107, 0, 0.707107}, res = 0; //������� ���'�� � ������ �����������
	cout << "������ �������� �: ";
	cin  >> a;
	cout << "������ ��� ������������ b � c" << endl; //���� ����� ������������
	cout << "����� ������� b = ";
	cin >> b;
	cout << "������ ������� c = ";
	cin >> c;
	xtrue = 0,4388245731174946;//����� ��������
	cout << "����'������ ��������: " << xtrue << endl;
	for (int i = 0; i < n; i++) //����������� ����� �
	{ 
		x[i] = ((b+c)/2) + ((c-b)*t[i])/2;
	}
	for (int i = 0; i < n; i++) // ������������ ������� ��������, 3 �����
	{
		double temp = (c - b) / n*atan(x[i]);
		res += temp;
	}
	cout << "�������� exp(" << a << "*x) ��������: " << res << endl; // ����� ������������
	cout << "���������� �����������: " << delta(xtrue, res) << endl; // ����� ���������� �����������
	cout << "������������� �����������: " << epsilon(xtrue, res) * 100 << "%" << endl; // ����� ������������� �����������

	system("pause");

	return 0;

}

double epsilon(double xtrue, double xfalse)// ³������ �������
{
	double epsilon;
	if (xfalse != 0)
	{
		epsilon = abs(xtrue - xfalse) / xtrue;
	}
	else epsilon = 0;
	return epsilon;
}

double delta(double xtrue, double xfalse)//��������� �������
{
	double delta = abs(xtrue - xfalse);
	return delta;
}
