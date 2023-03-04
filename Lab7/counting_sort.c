#include <stdio.h>
#include <stdlib.h>

// Function to take input an array A and return an array B after performing counting sort on it with array C
int* counting_sort(int* A, int* B, int k, int n) 
{
    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }
    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[A[j]]++;
    }
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    return B;
}

// Driver code to test the above function
int main() 
{
    FILE* fptr = fopen ("heights.txt", "r");
    int size ;

    while (fscanf(fptr,"%d,[", &size) == 1)
    {
        int A[size];
        for (int i = 0 ; i < size-1 ; i++)
        {
            fscanf(fptr,"%d,", &A[i]);
        }
        fscanf(fptr,"%d]\n", &A[size-1]);
        // Uncomment next 2 lines, to see if array is taken correctly.
        // for (int i = 0 ; i < size ; i++)
        //     printf("Element %d = %d\t", i, A[i]);
        int k = A[0];
        for (int i = 1; i < size; i++) 
        {
            if (A[i] > k) 
            {
                k = A[i];
            }
        }
        int B[size];
        int* sorted_array = counting_sort(A, B, k + 1, size);
        int cnt = 0;
        for (int i = 0 ; i < size ; i++)
        cnt += (sorted_array[i] == A[i]);

        printf("Ans is : %d\n", cnt);

    }
    // printf("\n");
    return 0;
}