#include "intMergeAux.h"
void mergeAux(PerPtr A, int s1, int e1, PerPtr B, int s2, int e2, PerPtr C, int s3, int e3)
{
    if (s1 > e1 && s2 > e2)
    return;
    if (s2 > e2)
    {
        makeEqual((C+s3), (A+s1));
        mergeAux(A,s1+1,e1,A,s2,e2,C,s3+1,e3);
        return;
    }
    if (s1 > e1)
    {
        makeEqual((C+s3), (B+s2));
        mergeAux(A,s1,e1,A,s2+1,e2,C,s3+1,e3);
        return;
    }
    if (A[s1].height > B[s2].height)
    {
        makeEqual((C+s3), (B+s2));
        mergeAux(A,s1,e1,A,s2+1,e2,C,s3+1,e3);
    }
    else
    {
        makeEqual((C+s3), (A+s1));
        mergeAux(A,s1+1,e1,A,s2,e2,C,s3+1,e3);
    }
}
