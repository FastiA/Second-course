#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int main(int argc, const char* argv[])
{
	TrapArray* theArray = createArray(8);
	//int* result = linSearch(theArray, 40);

	Point A = { 0,0 };
	Point B = { 4,4 };
	Point C = { 10,4 };
	Point D = { 14,0 };
	
	Trapeze ABCD = { &A, &B, &C, &D };

	addElement(theArray, &ABCD);
	TrapezeSquare(&ABCD);
	printf("%f\n", TrapezeSquare(&ABCD));
	printArray(theArray);

	A.x = 2;
	D.x = 11;

	addElement(theArray, &ABCD);
	TrapezeSquare(&ABCD);
	printf("%f\n", TrapezeSquare(&ABCD));
	printArray(theArray);

	B.y = 3;

	addElement(theArray, &ABCD);
	TrapezeSquare(&ABCD);
	printf("%f\n", TrapezeSquare(&ABCD));
	printArray(theArray);
	
	
	//linSearch(theArray, 40);
	//if (NULL != result)
	//{
		//printf("%f ", result);
	//}

    //bubblesort(theArray);

	fopen_s(&fo, "D:/test.json", "a+");

	writeArrayToJSON(fo, theArray);

	fflush(fo);
	fclose(fo);

	freeArray(theArray);

}

