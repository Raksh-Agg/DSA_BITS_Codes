#include "stack.h"
#include <stdio.h>
// #include "linked_list.h"
#include "heap_usage.h"
#include <sys/time.h>
// #include "
Element itoe (int i);
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
int main()
{
    // end();
    start();
    Stack *s = newStack();
    mem();
    if(isEmpty(s))
        printf("Stack is empty\n");
    
    push(s, itoe(1));
    mem();
    int value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    push(s, itoe(2));
    mem();
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    
    pop(s);
    end();


    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s)?"true":"false");
    // printf("Top Hol returned %d\n", top(push(s,itoe(7)))->int_value);

    printf("Trying to pop an empty stack\n");
    // printf("%d", s->list->count);
    printf("Pop returned %s\n", pop(s)?"true":"false");
    mem();

    freeStack(s);
    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}