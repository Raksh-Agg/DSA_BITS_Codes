#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>
#include "heap_usage.h"
// Adding Time Complexity code
#include <time.h>
__clock_t tv_begin;
__clock_t tv_end;
void start() 
{ tv_begin = clock(); }
void end()
{
    tv_end = clock();
    printf("No.of microsecond = %ld\n", (tv_end - tv_begin) );
}

//  input.csv is The input file given. Make sure the file's first line contains the no.of lines of input to be given to the code, and the next lines each contatining input..
int main()
{
    FILE* fptr = fopen ("marks.txt", "r");
    int size ;
    fscanf(fptr,"%d",&size);  
    int x;
    int *arr = (int*)myalloc(sizeof(int)*size);
    int i = 0;
    // To store file values in array
    while(fscanf(fptr,"%d",&x) != EOF)
    arr[i++]= x;
    start();
    mergeSort(arr,0,size-1);
    end();
    printf("Heap Memory used = %ld\n", heapMemoryAllocated);
    //To test OutPut, unComment the next 2 lines
    // for (int k = 0 ; k < size ; k++)
    // printf("%-7d\n", arr[k]);
    return 0;
}