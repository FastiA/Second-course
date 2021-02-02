#include <iostream>
#include "tool.h"
using namespace std;

Clock :: Clock(int hours, int minutes, int seconds)
{
	setClock(hours, minutes, seconds);
	cout << "create constructor of Clock: " << this << endl;
	system("pause");
}

istream& operator >> (istream& input, Clock& other)
{
	cout << ("¬ведите часы: ");
	cin >> other.hours;
	cout << ("¬ведите минуты: ");
	cin >> other.minutes;
	cout << ("¬ведите секунды: ");
	cin >> other.seconds;
	other.setClock(other.hours, other.minutes, other.seconds);
	return(input);
}

Clock :: Clock(const Clock& other)
{
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
	this->format = other.format;
	cout << "create constructor of Clock copy: " << this << endl;
}

int Clock::getHours()
{
	return hours;
}

int Clock::getMinutes()
{
	return minutes;
}

int Clock::getSeconds()
{
	return seconds;
}

int Clock::getFormat()
{
	return format;
}

Clock :: ~Clock()
{
	cout << "create destructor of Clock: " << this << endl;
}

ostream& operator << (ostream& output, Clock &other)
{
	output << "Hours: " <<other.hours << "," << " minutes: " << other.minutes << "," << " seconds: " << other.seconds<<","<<" format: " <<other.format<< endl;
	return output;
}

Clock Clock::operator++(int value)
{
	Clock temp(*this);

	this->seconds++;
	return temp;
}

Clock& Clock::operator++()
{
	this->seconds++;

	return *this;
}

Clock& Clock::operator = (const Clock& other)
{
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
	this->format = other.format;

	return *this;
}


void Clock ::clock()
{
	for (this->seconds; this->seconds <= 60; this->seconds++)
	{
		
		{
		
			if (this->seconds == 60)
			{
				this->minutes++;
			}
			if (this->minutes == 60)
			{
				this->hours++;
			}
			this->seconds = this->seconds % 60;
			this->minutes = this->minutes % 60;
			
			if (this->hours == this->format)
			{
				this->hours = this->hours % this->format;
				Clock::draw();
				system("pause");
			}
			
			Clock::draw();
		}

	}
}

int Clock::timer(int hours, int minutes, int seconds) 
{
	for (this->seconds; this->seconds <= 60; this->seconds++)
	{
			if (this->hours == hours && this->minutes == minutes && this->seconds == seconds)
			{
				Clock::draw();
				return 0;
			}

			else
			{

				if (this->seconds == 60)
				{
					this->minutes++;
				}
				if (this->minutes == 60)
				{
					this->hours++;
				}
				this->seconds = this->seconds % 60;
				this->minutes = this->minutes % 60;

				if (this->hours == this->format)
				{
					this->hours = this->hours % this->format;
					Clock::draw();
					system("pause");
				}

				Clock::draw();
			}
	}
}

void Clock ::setClock(int hours, int minutes, int seconds)
{

	this->format = 24;
	
	this->hours = hours;
	if (this->hours < 0 || this->hours > this->format)
	{
		do {
			cout << "¬ведите правильные часы!" << endl;
			cout << "¬водите новые часы:";
			this->hours = hours;
			cin >> this->hours;
		} while (this->hours < 0 || this->hours > this->format);
	}
	this->minutes = minutes;
	if (this->minutes < 0)
	{
		do {
			cout << "¬ведите правильные минуты!" << endl;
			cout << "¬водите новые минуты:";
			this->minutes = minutes;
			cin >> this->minutes;
		} while (this->minutes < 0);
	}
	this->seconds = seconds;
	if (this->seconds < 0)
	{
		do {
			cout << "¬ведите правильные секунды!" << endl;
			cout << "¬водите новые секунды:";
			this->seconds = seconds;
			cin >> this->seconds;
		} while (this->seconds < 0);
	}
	//this->format = format;
	/*if (this->format != 12 && this->format != 24)
	{
		do {
			cout << "¬ведите правильный формат времени!" << endl;
			cout << "¬водите новый формат:";
			this->format = format;
			cin >> this->format;
		} while (this->format != 12 && this->format != 24);
	}*/
}

void Clock :: draw()
{
	cout << "¬рем€: " << hours << ":" << minutes << ":" << seconds << endl;
}


Rectangl::Rectangl(int x1, int y1, int x2, int y2)
{
	setPoint(x1, y1, x2, y2);
	cout << "create constructor of Rectangle: " << this << endl;
	
}

Rectangl::~Rectangl()
{
	cout << "create destructor of Rectangle: " << this << endl;
}

istream& operator >> (istream& input, Rectangl& other)
{
	cout << ("¬ведите первую точку(координаты): ");
	cin >> other.X1 >> other.Y1;
	cout << ("¬ведите вторую точку(координаты): ");
	cin >> other.X2 >> other.Y2;
	other.setPoint(other.X1, other.Y1, other.X2, other.Y2);
	return(input);
}

void Rectangl::setPoint(int x1, int y1, int x2, int y2)
{
	this->X1 = x1;
	this->Y1 = y1;
	this->X2 = x2;
	this->Y2 = y2;
}

int Rectangl::getX1()
{
	return X1;
}

int Rectangl::getX2()
{
	return X2;
}

int Rectangl::getY1()
{
	return Y1;
}

int Rectangl::getY2()
{
	return Y2;
}

Rectangl& Rectangl:: operator = (const Rectangl& other)
{
	this->X1 = other.X1;
	this->X2 = other.X2;
	this->Y1 = other.Y1;
	this->Y2 = other.Y2;

	return *this;
}

void Rectangl::draw()
{
	cout << "Rectangle board " << "(A: " << X1 << "," << Y1 << ";" << " B: " << X2 << "," << Y2 << ")"<<endl;
}

ostream& operator << (ostream& output, Rectangl& other)
{
	output << "A: " << other.X1 << "," << other.Y1 << ";" << " B: " << other.X2 << "," << other.Y2 << endl;
	return output;
}

Rectangl Rectangl :: operator+(const Rectangl &other) 
{
	Rectangl temp;

	temp.X2 = this->X2 + other.X2;
	temp.Y2 = this->Y2 + other.Y2;

	return temp;
}

Rectangl::Rectangl(const Rectangl& other)
{
	this->X1 = other.X1;
	this->X2 = other.X2;
	this->Y1 = other.Y1;
	this->Y2 = other.Y2;
	
	cout << "create constructor of Rectangle copy: " << this << endl;
}


Circle::Circle(int x, int y, int r)
{
	setCircle(x, y, r);
	cout << "create constructor of Circle: " << this << endl;
}

Circle::~Circle()
{
	cout << "create destructor of Circle: " << this << endl;
}

istream& operator >> (istream& input, Circle& other)
{
	cout << ("¬ведите центр(координаты): ");
	cin >> other.X >> other.Y;
	cout << ("¬ведите радиус: ");
	cin >> other.R;
	other.setCircle(other.X, other.Y, other.R);
	return(input);
}

int Circle::getX()
{
	return X;
}

int Circle::getY()
{
	return Y;
}

int Circle::getRadius()
{
	return R;
}

void Circle::setCircle(int x, int y, int r)
{
	this->X = x;
	this->Y = y;
	this->R = r;
}

ostream& operator << (ostream& output, Circle& other)
{
	output << "—enter: "<<"(" << other.X<<","<<other.Y <<")"<<", Radius: "<<other.R << endl;
	return output;
}

Circle& Circle:: operator = (const Circle& other)
{
	this->X = other.X;
	this->Y = other.Y;
	this->R = other.R;

	return *this;
}

void Circle::draw()
{
	cout << "Circle board " << "(Center " << X << "," << Y << ";" << " Radius: " << R << ")" << endl;
}

Circle Circle :: operator+(const Circle& other)
 {
	 Circle temp;
	 
	 temp.R = this->R + other.R;

	 return temp;
 }

Circle::Circle(const Circle& other)
{
	this->X = other.X;
	this->Y = other.Y;
	this->R = other.R;

	cout << "create constructor of Circle copy: " << this << endl;
}
