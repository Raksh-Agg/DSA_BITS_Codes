#include <stdio.h>
#include <sys/time.h>
struct timeval t1,t2;
double time_taken;

int main(void)
{
    // Asks user for n as input and creates a square matrix of size nxn populating it with random integers
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int m1[n][n];
    int m2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m1[i][j] = rand() % 1000;
            m2[i][j] = rand() % 1000;
        }
    }
    int m3[n][n] ;
    gettimeofday(&t1, NULL);

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
            m3[i][j] = m2[i][j] + m1[i][j];
    }

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Taking Sum took %f seconds to execute\n", time_taken);
    int m4[n][n];
    gettimeofday(&t1, NULL);

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
            m4[j][i] = m2[j][i] + m1[j][i];
    }

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Taking Sum took %f seconds to execute\n", time_taken);

    
}