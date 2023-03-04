#include "counting_sort.c"
void swap (int* ptrone, int* ptrtwo)
{
	int temp = *ptrone;
	*ptrone = *ptrtwo;
	*ptrtwo = temp;
}
void binary_Radix_sort(int* arr, int begin, int end, int place)
{
	if (begin > end)
		return;
	if (place == 0)
		return;
	int zeros = begin, ones = end;
	while (zeros < ones)
	{
		if ((arr[zeros]&place) == 0)
		{
			zeros++;
			if ((arr[ones] & place) != 0)
				ones--;
		}
		else if ((arr[zeros]&place) != (arr[ones]&place) )
		{
			swap(arr+zeros, arr+ones);
			ones--;
			zeros++;
		}
		else 
		ones--;
	}
	int mid = begin;
	for (int i = begin+1 ; i <= end ; i++)
	{
		if ((arr[i-1]&place) != (arr[i]&place))
		{
			mid = i;
			break;
		}
		if (i == end)
		{
			if ((arr[i]&place) == place)
			mid = begin;
			else
			mid = end+1;
		}
		
	}
	binary_Radix_sort(arr, begin, mid-1, place/2);
	binary_Radix_sort(arr, mid, end, place/2);

}
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
		int max_2 = 1; 
		for (int i = 0 ; i < size ; i++)
			if(A[i]/max_2 > 0)
				max_2 *= 2;

        for (int i = 0 ; i < size ; i++)
            printf("%-4d\t", A[i]);
		printf("\n");
		binary_Radix_sort(A,0,size-1,max_2/2);
        // Uncomment next 3 lines, to see if array is taken correctly.
        for (int i = 0 ; i < size ; i++)
            printf("%-4d\t", A[i]);
		printf("\n");
    }
	return 0;
}
