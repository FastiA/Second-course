
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


int main(int argc, const char* argv[])
{
	List* list = createList();
	int elem;

	printf("Enter the number of elements:");
	scanf_s("%d", &elem);
	addElements(list, elem);

	printList(list);
	quickSort(list, 0, list->count - 1);
	printList(list);

	destroyList(list);
	return 0;
}