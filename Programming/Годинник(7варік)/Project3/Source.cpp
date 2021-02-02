#include <windows.h>
#include <iostream>
#include <stdio.h>
#include "tool.h"

using namespace std;


int main()
{
	setlocale(0, "");

	SYSTEMTIME lt;

	GetLocalTime(&lt);

	Rectangl board1(0, 0, 4, 5);

	cin >> board1;
	cout << board1;
	++board1;

	board1.setClock(lt.wHour, lt.wMinute, lt.wSecond);
	board1.draw();
	board1.timer(lt.wHour, lt.wMinute + 5, lt.wSecond);

	
	Circle board2(0, 0, 4);
  
	cout << board2;
	board2.setClock(lt.wHour, lt.wMinute, lt.wSecond);
	board2.draw();


	Clock* c = &board1;
	c->draw();

	return 0;
}