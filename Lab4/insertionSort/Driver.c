#include "insSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//  input.csv is The input file given. Make sure the file's first line contains the no.of lines of input to be given to the code, and the next lines each contatining input..
int main()
{
    FILE* fptr = fopen ("input.csv", "r");
    int size;
    fscanf(fptr,"%d",&size);
    PerPtr Array = (PerPtr)malloc(size * sizeof(Person));
    char line[75];
    char *token;
    fgets(line, 75, fptr);
    // Test string for storing name correctly
    char * test_string;
    // Code for taking input from file for Person
    for (int j = 0 ; j < size ; j++)
    {
        fgets(line, 75, fptr);
        token = strtok(line, ",");
        (Array+j)->id = atoi(token);
        test_string = (char*)malloc(20);
        token = strtok(NULL, ",");
        memcpy(test_string, token, strlen(token));
        Array[j].name = test_string;
        token = strtok(NULL, ",");
        (Array+j)->age = atoi(token);
        token = strtok(NULL, ",");
        (Array+j)->height = atoi(token);
        token = strtok(NULL, ",");
        (Array+j)->weight = atoi(token);
        token = strtok(NULL, ",");
    }
    insertionSort(Array, size);
    for (int i = 0 ; i < size ; i++)
    print(*(Array+i));
    return 0;
}