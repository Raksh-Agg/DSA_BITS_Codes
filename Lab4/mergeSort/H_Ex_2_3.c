#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>
// To run this, use command :
// gcc intMergeAuxIter.c intMerge.c H_Ex_2_3.c -o runguy && ./runguy

int main()
{
    int arr[4] = {3,1,1,3};
    int size = 4;
    mergeSort(arr,0,size-1);
    for (int i = 0 ; i < size ; i++)
    {
        if (arr[i] == (size-i-1))
        {
            printf("%d\n", arr[i]);
            return 0;
        }
    }
    printf("No such integer found\n");
    
    return 0;
}