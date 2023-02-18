#include "linked_list.h"
#include "heap_usage.h"
// #include "element.h"
// #include "stack.h"
#include <stdlib.h>
#include <stdio.h>
LIST createNewList()
{
    LIST head = (LIST)malloc(sizeof(linked_list));
    head->count = 0;
    return head;
}
NODE createNewNode(int data)
{
    NODE newnode = (NODE)malloc(sizeof(node));
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
void insertNodeAtEnd(NODE node, LIST list)
{
    NODE ptr = list->head;
    if (list->count == 0)
    insertNodeIntoList(node,list);
    else
    {
        while (ptr->next != NULL)
        ptr = ptr->next;
        ptr->next = node;
    }
}
void destroyList(LIST list)
{
    while (list->count != 0)
    {
        removeFirstNode(list);
        list->count--;
    }
    // free(&list);
}
