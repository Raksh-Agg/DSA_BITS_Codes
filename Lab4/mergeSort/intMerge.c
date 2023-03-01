#include "intMerge.h"
// #include "heap_usage.h"
#include "Person.h"
void merge(PerPtr A, int s, int mid, int e)
{
    PerPtr C = (PerPtr)malloc(sizeof(Person)*(e-s+1));
    int i = s;
    int j = mid+1;
    mergeAux(A,s,mid,A,mid + 1, e, C, 0, e-s);
    // To store final sorted array contents back in A
    for (int i = 0 ; i <= e-s ; i++)
    makeEqual((A+s+i), (C+i));
    free(C);
}
void mergeSort (PerPtr A, int st, int en)
{
    if (en - st < 1) return;
    int mid = (st+en)/2;
    mergeSort(A, st, mid);
    mergeSort(A, mid+1, en);
    merge(A, st, mid, en);

}
