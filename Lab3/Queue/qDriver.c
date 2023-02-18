#include "queue.h"
#include "heap_usage.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

Element* itoe (int mypid, int myartime, int myburst)
{
    Element* hehe = (Element*)malloc (sizeof(Element));
    hehe->pid = mypid;
    hehe->arrival_time = myartime;
    hehe->burst_time = myburst;
    return hehe;
}
int main()
{
    Queue* q = createQueue();
    FILE* fptr = fopen("fcfs_input.txt", "r");
    int numOfProcess = 0;
    fscanf(fptr, "%d", &numOfProcess);
    while (numOfProcess--)
    {
        int mypid, myartime, myburst;
        fscanf(fptr, "%d %d %d", &mypid, &myartime, &myburst);
        enqueue(q, *itoe(mypid, myartime, myburst));
    }
    int time = 0;
    while (!isEmpty(q))
    {
        time = (time > front(q)->arrival_time ) ? time : front(q)->arrival_time;
        printf("Process %d started at time %d\n", front(q)->pid, time);
        time += front(q)->burst_time;
        printf("Process %d finished at time %d\n", front(q)->pid, time);
        dequeue(q);
    }


}