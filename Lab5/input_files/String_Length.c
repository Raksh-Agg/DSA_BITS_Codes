#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
struct timeval t1, t2;
double time_taken;
long lengthNTR(char *str)
{
    if (*str == '\0')
        return 0;
    else
        return 1 + lengthNTR(str + 1);
}
long lengthTR(char *str, long mySum)
{
    if (*str == '\0')
        return mySum;
    else
        return lengthTR(str+1, mySum+1);
}
long lengthIter(char *str)
{
    long mySum = 0;
    while (*str != '\0')
    {
        mySum++;
        str = str+1;
    }
    return mySum;
}
long giveLength(char *str)
{
    return lengthIter(str);
}
int main()
{
    FILE* fptr = fopen ("String.txt", "r");
    char str[20000];
    fgets(str,20000,fptr);
    gettimeofday(&t1, NULL);

    printf("%ld\n", giveLength(str));

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Taking Sum took %f seconds to execute\n", time_taken);
    return 0;
}