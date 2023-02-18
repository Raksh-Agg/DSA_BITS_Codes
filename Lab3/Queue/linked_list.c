#include "linked_list.h"
#include "heap_usage.h"
// #include "element.h"
// #include "stack.h"
#include <stdlib.h>
#include <stdio.h>
LIST createNewList()
{
    LIST list = (LIST)myalloc(sizeof(linked_list));
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}
NODE createNewNode(Element data)
{
    NODE newnode = (NODE)myalloc(sizeof(node));
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
    if (list->tail == NULL)
        list->tail = newnode;
    newnode->next = list->head;
    list->head = newnode;
    list->count++;
}
bool removeFirstNode(LIST list)
{
    if (list == NULL)
    {
        printf("Given list does not exist\n");
        return false;
    }
    if (list->count == 0)
    {
        printf("List is empty\n");
        return false;
    }
    if (list->tail == list->head)
        list->tail = NULL;
    NODE ptr = list->head;
    list->head = ptr->next;
    myfree(ptr);
    list->count--;
    return true;
}
void insertNodeAtEnd(NODE node, LIST list)
{
    if (list->tail == NULL)
    {
        insertNodeIntoList(node, list);
        return;
    }
    list->tail->next = node;
    list->tail = node;
    list->count++;
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
