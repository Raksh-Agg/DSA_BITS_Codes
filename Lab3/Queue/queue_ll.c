#include "queue.h"
#include "heap_usage.h"
#include "linked_list.h"
struct Queue
{
    LIST list;
};
Queue *createQueue()
{
    Queue* newQ = (Queue*)myalloc(sizeof(Queue));
    newQ->list = createNewList();
    return newQ;
}
bool enqueue(Queue *queue, Element element)
{
    insertNodeAtEnd(createNewNode(element), queue->list);
    return true;
}
bool dequeue(Queue *queue)
{
    return removeFirstNode(queue->list);
    // return true;
}
Element *front(Queue *queue)
{
    return &(queue->list->head->data);
}
int size(Queue *queue)
{
    return queue->list->count;
}
bool isEmpty(Queue *queue)
{
    return !(queue->list->count);
}
void destroyQueue(Queue *queue)
{
    destroyList(queue->list);
}