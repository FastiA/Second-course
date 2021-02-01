#include "tool.h"
#include <stdlib.h>
#include <math.h>


int lenght = 10000;

char* getArray(char* path_to_file)
{
	errno_t err;
	int i = 0;
	char* array = malloc(sizeof(char) * lenght);
	err = fopen_s(&fo, path_to_file, "rt");
	if (err == 0)
	{
		while (i < lenght)
		{
			fscanf_s(fo, "%c", &array[i]);
			i++;
		}

		fclose(fo);
		return array;
	}
	else
	{
		printf("Wrong file path\n");
	}

}

void writeArray(char* array, char* path_to_file)
{

	int i;
	fopen_s(&fo, path_to_file, "at");

	{
		for (i = 0; i < lenght; i++)
		{
			fprintf(fo, "%c", array[i]);
			printf("%c", array[i]);
		}

		fprintf(fo, "\n");
		printf("\n");
		fclose(fo);
	}

}