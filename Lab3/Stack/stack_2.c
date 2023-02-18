#include "linked_list.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "heap_usage.h"
struct Stack
{
    LIST list;
};
Stack *newStack()
{
    Stack * newStack = (Stack*)malloc(sizeof(Stack));
    newStack->list = createNewList();
    return newStack;
} 
bool push(Stack *stack, int element)
{
    insertNodeIntoList(createNewNode(element),stack->list);
}
int *top(Stack *stack)
{
    if (stack->list->count == 0)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    return &(stack->list->head->data);
}
bool pop(Stack *stack)
{
    if (stack->list->count == 0)
    {
        printf("Stack is empty\n");
        return false;
    }
    removeFirstNode(stack->list);
    return true;
}
bool isEmpty(Stack *stack)
{
    return !(stack->list->count);
}
void freeStack(Stack *stack)
{
    while (isEmpty(stack) != true)
    pop(stack);
    // free(stack);
}
int sizeStack (Stack *stack)
{
    return stack->list->count;
}