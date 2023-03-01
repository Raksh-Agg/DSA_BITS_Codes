#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>
//  input.csv is The input file given. Make sure the file's first line contains the no.of lines of input to be given to the code, and the next lines each contatining input..
int main()
{
    FILE* fptr = fopen ("marks.txt", "r");
    int size ;
    fscanf(fptr,"%d",&size);  
    int x;
    int *arr = (int*)malloc(sizeof(int)*size);
    int i = 0;
    // To store file values in array
    while(fscanf(fptr,"%d",&x) != EOF)
    arr[i++]= x;
    mergeSort(arr,0,size-1);
    //To test OutPut, unComment the next 2 lines
    // for (int k = 0 ; k < size ; k++)
    // printf("%-7d\n", arr[k]);
    return 0;
}