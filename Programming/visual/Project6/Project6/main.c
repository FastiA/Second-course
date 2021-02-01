#include <stdio.h>
#include "tool.h"
#include <string.h>


int main(int argc, const char* argv[])
{
	int base;
	char str[100];
	int c;
	

	printf("Wwedit chisla dla funk sumi, chislo C i shisnat chislo:\n");
	scanf_s("%i %i\n", &base, &c);
	scanf_s("%s \n", str);
	
	//printf("Widpowid:%", &q);

}

int end(int base, int c, char* a)
{
	int result = u_system(a);

	int sum = suma(base, c);

	return(result * (sum - c));
}