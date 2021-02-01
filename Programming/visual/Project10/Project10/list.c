#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h> 

List* createList()
{
	List* theList = (List*)malloc(sizeof(List));

	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}

	return theList;
}

Node* createNode(double value)
{
	Node* theNode = (Node*)malloc(sizeof(Node));

	if (NULL != theNode)
	{
		theNode->value = value;
		theNode->next = NULL;
	}

	return theNode;
}

void addNode(List* aList, Node* aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
	{
		return;
	}

	if (NULL == aList->head && aList->head == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		Node* theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->next = aList->tail;
		}
	}

	aList->count += 1;

	return aNewNode;
}



void addElements(List* aList, int i)
{
	if (i < 1)
	{
		printf("Invalid value");
		return;
	}

	srand(time(NULL));
	for (i; i >= 0; i--)
	{
		double random1;
		double random2;
		double random;
		random1 = rand() % 1000;
		random2 = rand() % 1000;
		random = random1 / random2;
		addNode(aList, createNode(random));
	
	}
}
void printList(List* aList)
{
	if (NULL == aList->head)
	{
		return;
	}

	int i = 0;
	Node* theNode = aList->head;

	while (1)
	{
		if (NULL != theNode)
		{
			printf("Node[%d] = %f\n", i + 1, theNode->value);
		}
		i++;
		theNode = theNode->next;

		if (NULL == theNode->next)
		{
			break;
		}
	}
	printf("\n");
}

int searchMax(List* aList)
{
	Node* theNode = aList->head;

	int max = theNode->value;
	while (NULL != theNode->next)
	{
		if (theNode->next->value > max)
		{
			max = theNode->next->value;
		}
		theNode = theNode->next;
	}
	return max;
}

int countBeforeMax(List* aList, int max)
{
	if (NULL == aList->head)
	{
		return;
	}

	int count = 0;
	Node* theNode = aList->head;

	while (1)
	{
		if (NULL != theNode && theNode->value != max)
		{
			count++;
		}
		else
		{
			return count;
		}

		theNode = theNode->next;
	}
}

void bubbleSort(List* aList, int count)
{
	if (NULL != aList)
	{
		if (aList->count <= 1)
		{
			return;
		}

		int temp;
		unsigned int i = 0;
		Node* theNode = aList->head;
		bool isSwaped = true;

		while (isSwaped)
		{
			isSwaped = false;
			theNode = aList->head;
			for (i = 0; i < count; ++i)
			{
				if (theNode->value > theNode->next->value)
				{
					temp = theNode->value;
					theNode->value = theNode->next->value;
					theNode->next->value = temp;
					isSwaped = true;
				}
				theNode = theNode->next;
			}
		}

	}
	return;
}

void destroyList(List* aList)
{
	if (NULL == aList)
	{
		return;
	}

	Node* theNode = aList->head;
	while (NULL != theNode)
	{
		Node* toRemove = theNode;
		theNode = theNode->next;
		free(toRemove);
	}

	free(aList);
}


int partitionIt(List* aList, int aLeftIndex, int aRightIndex, double aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;

	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && SLNodeAtIndex(aList, ++theLeft)->value < aPivot);

		// search the lowest element
		while (theRight > aLeftIndex && SLNodeAtIndex(aList, --theRight)->value > aPivot);

		if (theLeft >= theRight)
		{
			break;
		}
		else
		{
			swapNodesByIndex(aList, theLeft, theRight);
		}
	}

	return theLeft;
}


void quickSort(List* aList, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; 
	}

	int thePivot = SLNodeAtIndex(aList, aRightIndex)->value;
	int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);

	quickSort(aList, aLeftIndex, thePartitionIndex - 1);
	quickSort(aList, thePartitionIndex + 1, aRightIndex);
}


Node* SLNodeAtIndex(List* aList, int anIndex)
{
	Node* theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		Node* theNode = aList->head;

		do
		{
			if (i == anIndex) 
			{
				theResult = theNode; 
				break;
			}

			i++;
			theNode = theNode->next;

		} while (NULL != theNode);
	}

	return theResult;
}

void swapNodesByIndex(List* aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return;

	Node* theLeftNode = SLNodeAtIndex(aList, aLeftIndex);
	Node* theRightNode = SLNodeAtIndex(aList, aRightIndex);

	double theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}
