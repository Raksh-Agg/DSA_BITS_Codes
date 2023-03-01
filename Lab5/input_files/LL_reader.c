#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
struct timeval t1, t2;
double time_taken;


typedef struct node * NODE;
struct node{
    int ele;
    NODE next;
};


typedef struct linked_list * LIST;
struct linked_list{
    int count;
    NODE head;
};


LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}


NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}

// Recursive function to compute sum of integers in a linked list
long long llSumNTR(NODE head, long long mySum)
{
    if (head == NULL)
        return mySum;
    return llSumNTR(head->next, mySum + head->ele); // Pay close attention here
}

// This is just a wrapper function to take LIST as input, but run the recursive sum function on its NODEs starting from the head
long long llSumNTRWrapper(LIST list)
{
    return llSumNTR(list->head, 0);
}

// Driver code
int main()
{
    // Reads the file numbers1000.txt and creates a linked list with those integers
    FILE *fp;
    fp = fopen("numbers1000000.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int num;
    LIST myList = createNewList();
    while (fscanf(fp, "%d", &num) != EOF)
    {
        NODE myNode = createNewNode(num);
        myNode->next = myList->head;
        myList->head = myNode;
        myList->count++;
    }
    fclose(fp);

    // Perform some operations on the linked list
    // ...
    gettimeofday(&t1, NULL);

    printf("%lld\n", llSumNTRWrapper(myList));

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Taking Sum took %f seconds to execute\n", time_taken);

    // Example operation: Print the elements of the linked list
    // NODE temp = myList->head;
    // while (temp != NULL)
    // {
    //     printf("%d ", temp->ele);
    //     temp = temp->next;
    // }
}