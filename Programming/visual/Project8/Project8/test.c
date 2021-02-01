#include <stdio.h>

int main()
{
	int base = 4;
	int finish = 5;
	int result = 0;

	for (int i = 1; i <= finish; i++)
	{
		result += base;
	}

	printf("%i", result);
}