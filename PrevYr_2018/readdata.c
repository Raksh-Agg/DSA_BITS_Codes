#include"node.h"
#include<stdio.h>
#include<stdlib.h>

Member* makeMember(int id)
{
	Member* newM = (Member*)malloc(sizeof(Member));
	newM->id = id;
	newM->next = NULL;
	return newM;
}
void insertAtEndOfList(Member* mm, Locality* ll)
{
	if (ll->count == 0)
	{
		ll->first = mm;
		ll->count++;
	}
	else if (ll->count == 1)
	{
		ll->first->next = mm;
		ll->count++;
	}
	else
	{
		Member* ptr = ll->first;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = mm;
		ll->count++;
	}
}
Locality * ReadFileintoLists(char *filename)
{
	FILE* fptr = fopen (filename, "r");
	int size = 0;
	Locality* LL_main = (Locality*)malloc(sizeof(Locality));
	LL_main->count = N;
	LL_main->first = NULL;
	LL_main->next = NULL;
	Locality* ptr = LL_main;
	for (int i = 0 ; i < N ; i++)
	{
		fscanf(fptr, "%d,", &size);
		Locality* newLL = (Locality*)malloc(sizeof(Locality));
		newLL->count = size;
		newLL->next = NULL;
		newLL->first = NULL;
		int x;
		while (size--)
		{
			fscanf(fptr,"%d," ,&x);


		}

		
	}
}

void PrintLists (Locality *start)
{
}
