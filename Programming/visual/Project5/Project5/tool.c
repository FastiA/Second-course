#include <string.h>
#include <stdio.h>
#include <tool.h>


int system(char str[10])
{
	int i, kil, p;
	int sum = 0;
	kil = strlen(str) - 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		switch (toupper(str[i]))
		{
			case 'A': p = 10;
			break;
			case 'B': p = 11;
			break;
			case 'C': p = 12;
			break;
			case 'D': p = 13;
			break;
			case 'E': p = 14;
			break;
			case 'F': p = 15;
			break;
			case '1': p = 1;
			break;
			case '2': p = 2;
			break;
			case '3': p = 3;
			break;
			case '4': p = 4;
			break;
			case '5': p = 5;
			break;
			case '6': p = 6;
			break;
			case '7': p = 7;
			break;
			case '8': p = 8;
			break;
			case '9': p = 9;
			break;
			case '10': p = 10;
			break;
			
		}
		sum = sum + p * pow(16, kil);
		kil--;

	}

	return 0;
}

int suma(int base, int finish)
{
	int result = 1;

	for (int i = 1; i < finish; i++)
	{
		result += base;
	}

	return result;
}

