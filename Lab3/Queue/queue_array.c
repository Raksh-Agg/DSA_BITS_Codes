#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
Queue *createQueue()
{
    Queue* newQ = (Queue*)malloc (sizeof(Queue));
    newQ->front = 0;
    newQ->rear = 0;
    return newQ;
}
bool enqueue(Queue *queue, Element element)
{
    if (queue->rear == MAX_SIZE)
    {
        printf("Max size of Q has been reached\n");
        return false;
    }
    queue->data[(queue->rear)++] = element;
}
bool dequeue(Queue *queue)
{
    if (queue->front == queue->front)
    {
        printf("Q is empty, no element to remove\n");
        return false;
    }
    (queue->front)++;
}
Element *front(Queue *queue)
{
    if (queue->rear == queue->front)
    {
        printf("Q is empty, no element to remove\n");
        return NULL;
    }
    return &((queue->data)[queue->front]);
}
int size(Queue *queue)
{
    return (queue->front - queue->rear);
}
bool isEmpty(Queue *queue)
{
    return !(queue->front - queue->rear);
}
void destroyQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}
