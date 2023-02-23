#include "insSort.h"
#include <stdio.h>
#include <time.h>
void insertionSort(PerPtr arr, int size)
{
    __clock_t tv_begin;
    __clock_t tv_end;
    tv_begin = clock();
    for (int i = 0 ; i < size ; i++)
    insertInOrder(arr[i], arr, i);
    tv_end = clock();
    printf("No.of microsecond = %ld\n", (tv_end - tv_begin) );
}
void insertInOrder (Person ele, PerPtr arr, int index)
{
    while (index > 0 && ele.height < arr[index-1].height)
    {
        arr[index] = arr[index-1];
        arr[index-1] = ele;
        index--;
    }
}
