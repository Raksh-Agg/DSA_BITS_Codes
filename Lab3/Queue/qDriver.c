#include "queue.h"
#include "heap_usage.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
struct timeval tv_begin;
struct timeval tv_end;
void start() { gettimeofday(&tv_begin, NULL); }
void end()
{
    gettimeofday(&tv_end, NULL);
    printf("No.of microsecond = %ld\n", (tv_end.tv_sec - tv_begin.tv_sec) +
  (tv_end.tv_usec - tv_begin.tv_usec));
}
void mem() { printf("Memory used is = %ld\n", heapMemoryAllocated); }

Element* itoe (int i)
{
    Element* hehe = (Element*)malloc (sizeof(Element));
    hehe->int_value = i;
    hehe->float_value = 2.4f;
    return hehe;
}
int main()
{
    Queue* q = createQueue();
    // mem();
    if (isEmpty(q))
    printf("This Queue is empty\n");
    enqueue(q, *(itoe(55)));
    printf("Element at first is %d\n", front(q)->int_value);
    // mem();
    enqueue(q, *(itoe(89)));
    printf("Element at first is %d\n", front(q)->int_value);
    // mem();
    dequeue(q);
    // mem();
    printf("Element at first is %d\n", front(q)->int_value);
    printf("Size of Queue is %d\n", size(q));
    printf("What does deQueue return %d\n", dequeue(q));
    printf("What does deQueue return %d\n", dequeue(q));
    printf("Is Queue empty : %d\n", isEmpty(q));
    destroyQueue(q);
    
    // mem();
    printf("Is Queue empty : %d\n", isEmpty(q));

}