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


// ---
LIST createNewList()
{
    LIST ll = (LIST)malloc(sizeof(linked_list));
	// ll->head = (NODE) malloc(sizeof(NODE));
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
	// printf("%d\n", list->count);
    // list->head = newnode;
	list->head = newnode;
	// printf("hehe\n");
    list->count++;
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

void bucket_sort (int* arr, int size)
{

	int maxval = 0;
	for (int i = 0 ; i < size ; i++)
		if (maxval < arr[i])
			maxval = arr[i];

	LIST heads[maxval+1];
	for (int i = 0 ; i <= maxval ; i++)
		heads[i] = createNewList();
	for (int i = 0 ; i < size; i ++)
		insertNodeIntoList(createNewNode(arr[i]),heads[arr[i]]);
	
	size_t pos = 0;
	for (int i = 0 ; i <= maxval ; i ++)
	{
		while (heads[i]->count > 0)
		{
			arr[pos] = i;
			removeFirstNode(heads[i]);
			pos++;
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
        for (int i = 0 ; i < size ; i++)
            printf("%d\n", A[i]);
		printf("\n");
		bucket_sort(A,size);
        // Uncomment next 3 lines, to see if array is taken correctly.
        for (int i = 0 ; i < size ; i++)
            printf("%d\n", A[i]);
		printf("\n");
    }

	return 0;
}
