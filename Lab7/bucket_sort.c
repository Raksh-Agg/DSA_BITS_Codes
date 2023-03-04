#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
	int data;
	struct node* next;
} Node ;
typedef struct linked_list 
{
	int count;
	Node* head;
} linked_list;
typedef linked_list* LIST;
typedef Node* NODE;

LIST createNewList()
{
    LIST ll = (LIST)malloc(sizeof(linked_list));
	ll->head = NULL;
	ll->count = 0;
    return ll;
}
NODE createNewNode(int data)
{
    NODE newnode = (NODE)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertNodeIntoList(NODE newnode, LIST list)
{
    if (list == NULL)
    {
        printf("Given list does not exist");
        return;
    }
    newnode->next = list->head;
	list->head = newnode;
    list->count++;
}
void insertInOrder (NODE newnode, LIST list)
{
	if (list->count == 0)
	insertNodeIntoList(newnode, list);
	else
	{
		NODE ptr = list->head;
		if (ptr->data > newnode->data)
			insertNodeIntoList(newnode, list);
		else
		{
			while ((ptr->next != NULL) && (newnode->data > ptr->next->data) )
			ptr = ptr->next;
			newnode->next = ptr->next;
			ptr->next = newnode;
			list->count++;
		}
	}

}
void removeFirstNode(LIST list)
{
    if (list == NULL)
    {
        printf("Given list does not exist\n");
        return;
    }
    if (list->count == 0)
    {
        printf("List is empty\n");
        return;
    }
    NODE ptr = list->head;
    list->head = ptr->next;
    free(ptr);
    list->count--;
}
void destroyList(LIST list)
{
    while (list->count != 0)
    {
        removeFirstNode(list);
        list->count--;
    }
}

void modified_bucket_sort (int* arr, int size)
{
	int maxval = 0;
	for (int i = 0 ; i < size ; i ++)
		if (maxval < arr[i])
			maxval = arr[i];
	maxval /= 10;
	LIST heads[maxval+1];
	for (int i = 0 ; i <= maxval ; i ++)
		heads[i] = createNewList();
	for (int i = 0 ; i < size ; i ++)
	insertInOrder(createNewNode(arr[i]), heads[arr[i]/10]);
	int pos = 0;
	for (int i = 0 ; i <= maxval ; i++)
	{
		while (heads[i]->count > 0)
		{
			arr[pos++] = heads[i]->head->data;
			removeFirstNode(heads[i]);
		}
	}
}
int main()
{
	FILE* fptr = fopen ("thing.txt", "r");
    int size ;
    while (fscanf(fptr,"%d,[", &size) == 1)
    {
        int A[size];
        for (int i = 0 ; i < size-1 ; i++)
        {
            fscanf(fptr,"%d\t", &A[i]);
        }
        fscanf(fptr,"%d]\n", &A[size-1]);

		modified_bucket_sort(A,size);
        // Uncomment next 3 lines, to see if array is taken correctly.
        // for (int i = 0 ; i < size ; i++)
        //     printf("%d\t", A[i]);
		// printf("\n");
    }

	return 0;
}
