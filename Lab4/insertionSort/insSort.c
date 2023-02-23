#include "insSort.h"
#include <stdio.h>
void insertionSort(PerPtr arr, int size)
{
    for (int i = 0 ; i < size ; i++)
    insertInOrder(arr[i], arr, i);
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
