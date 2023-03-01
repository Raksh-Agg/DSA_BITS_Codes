#include "intMergeAux.h"
void mergeAux(PerPtr A, int s1, int e1, PerPtr B, int s2, int e2, PerPtr C, int s3, int e3)
{
    int i = s1;
    int j = s2;
    int k = s3;
    while (i <= e1 && j <= e2)
    {
        if (A[i].height > B[j].height)
        {
            makeEqual((C+k), (B+j));
            j++;
        }
        else
        {
            makeEqual((C+k), (A+i));
            i++;
        }
        k++;
    }
    while (i <= e1)
    {
        makeEqual((C+k), (A+i));
        i++;
        k++;
    }
    while (j <= e2)
    {
        makeEqual((C+k), (B+j));
        j++;
        k++;
    }
}
