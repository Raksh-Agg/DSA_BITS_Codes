#include "counting_sort.c"
int main ()
{
	FILE* fptr = fopen ("n_integers.txt", "r");
    int size ;

    while (fscanf(fptr,"%d,[", &size) == 1)
    {
        int A[size];
        for (int i = 0 ; i < size-1 ; i++)
        {
            fscanf(fptr,"%d\t", &A[i]);
        }
        fscanf(fptr,"%d]\n", &A[size-1]);
        int B[size];
		for (int i = 1 ; i <= 1000 ; i *= 10)
        Radix_counting_sort(A, B, 10, size, i);
        // Uncomment next 3 lines, to see if array is taken correctly.
        // for (int i = 0 ; i < size ; i++)
        //     printf("%-4d\t", A[i]);
		// printf("\n");
    }
	return 0;
}
