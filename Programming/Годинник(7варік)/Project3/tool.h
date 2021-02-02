#ifndef tool_h
#define tool_h
#include <iostream>
using namespace std;

class Clock
{

private:
	int hours,
		minutes,
		seconds,
		format;
public:
	Clock(int hours = 0, int minutes = 0, int seconds = 0);
	Clock(const Clock& other);
	~Clock();
	Clock& operator++();
	Clock operator++(int);
	Clock& operator = (const Clock& other);
	int getHours();
	int getMinutes();
	int getSeconds();
	int getFormat();
	int timer(int hours, int minutes, int seconds);
	void clock();
	void setClock(int hours, int minutes, int seconds);
	virtual void draw();
	
	friend istream& operator >>(istream& input, Clock& other);
	friend ostream& operator << (ostream& os, Clock& other);
};


class Rectangl : public Clock
{
private:
	int X1,
		Y1,
		X2,
		Y2;

public:
	Rectangl(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	Rectangl(const Rectangl& other);
	~Rectangl();
	Rectangl& operator = (const Rectangl& other);
	Rectangl operator+(const Rectangl& other);
	int getX1();
	int getX2();
	int getY1();
	int getY2();
	void setPoint(int x1, int y1, int x2, int y2);
	void draw();
	
	friend istream& operator >>(istream& input, Rectangl& other);
	friend ostream& operator << (ostream& output, Rectangl& other);
};


class Circle : public Clock
{
private:
	int X,
		Y,
		R;

public:
	Circle(int x = 0, int y = 0, int r = 0);
	Circle(const Circle& other);
	~Circle();
	Circle& operator = (const Circle& other);
	Circle operator+(const Circle& other);
	int getX();
	int getY();
	int getRadius();
	void setCircle(int x, int y, int r);
	void draw();
	
	friend istream& operator >>(istream& input, Circle& other);
	friend ostream& operator << (ostream& output, Circle& other);
};

#endif tool_h