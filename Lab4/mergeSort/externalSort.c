#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Initializing stuff 
// For this code to work, you need to have file dat7578440.csv in the directory, which, I cannot do, since GITHUB has a limit of file size.
int size = 7578440 ;
int general_size = 975000;
int last_size;
char file_name[10] = "outx.csv";
int sizes[9] = {0,975000,975000,975000,975000,975000,975000,975000,753440};

void doMergeForFile (int index);
void bigMerge (char file1[], char file2[], char file3[]);

int main()
{
    last_size = size - 7*general_size;
    FILE* fptr = fopen ("dat7578440.csv", "r");
    char line[70];
    FILE* fptx;
    printf("%ld\n", sizeof(Person));
    for (int i = 0 ; i < 7 ; i++)
    {
        file_name[3] = (char)(i+'1');
        fptx = fopen (file_name, "w");
        for (int j = 0 ; j < general_size ; j++)
        {
            fgets(line, 70, fptr);
            fputs(line, fptx);
        }
        fclose (fptx);
    }
    fptx = fopen ("out8.csv", "w");
    for (int i = 0 ; i < last_size ; i++)
    {
        fgets(line, 70, fptr);
        fputs(line, fptx);
    }
    fclose(fptx);
    fclose(fptr);

    for (int i = 0 ; i < 8 ; i++)
        doMergeForFile(i);
    bigMerge("out1.csv", "out2.csv", "out0.csv");
    bigMerge("out3.csv", "out4.csv", "out1.csv");
    bigMerge("out5.csv", "out6.csv", "out2.csv");
    bigMerge("out7.csv", "out8.csv", "out3.csv");
    bigMerge("out0.csv", "out1.csv", "out4.csv");
    bigMerge("out2.csv", "out3.csv", "out5.csv");
    bigMerge("out4.csv", "out5.csv", "input.csv");
    return 0;

}

void bigMerge (char file1[], char file2[], char file3[])
{
    FILE* ptr1, *ptr2, *ptr3;
    ptr1 = fopen(file1, "r");
    ptr2 = fopen(file2, "r");
    ptr3 = fopen(file3, "w");
    int size1 = sizes[file1[3] - '0'], size2 = sizes[file2[3] - '0'];
    int i = 0,j = 0,k = 0;

    char line1[70];
    char line1_rep[70];
    char line2[70];
    char line2_rep[70];
    char *token;
    int h1, h2;

    while (i < size1 && j < size2)
    {
        fgets(line1, 70, ptr1);
        fgets(line2, 70, ptr2);
        memcpy(line1_rep, line1, 70);
        memcpy(line2_rep, line2, 70);
        token = strtok(line1, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        h1 = atoi(token);
        token = strtok(line2, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        h2 = atoi(token);

        if (h1 > h2)
        {
            fputs(line2_rep, ptr3);
            fputs(line1_rep, ptr3);
        }
        else
        {
            fputs(line1_rep, ptr3);
            fputs(line2_rep, ptr3);
        }
        i++;
        j++;
    }
    while (i < size1)
    {
        fgets(line1, 70, ptr1);
        fputs(line1, ptr3);
        i++;
    }
    while (j < size2)
    {
        fgets(line2, 70, ptr1);
        fputs(line2, ptr3);
        j++;
    }
    if (file3[0] != 'i')
    sizes[file3[3] - '0'] = sizes[file1[3] - '0'] + sizes[file2[3] - '0'];
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
}

void doMergeForFile (int index)
{
    size = sizes[index + 1];
    file_name[3] = (char)(index+'1');
    FILE* pntr = fopen (file_name, "r");
    PerPtr Array = (PerPtr)malloc(size * sizeof(Person));
    char line[70];
    char *token;
    for (int j = 0 ; j < size ; j++)
    {
        fgets(line, 70, pntr);
        token = strtok(line, ",");
        (Array+j)->id = atoi(token);
        char* test_string = (char*)malloc(20);
        token = strtok(NULL, ",");
        memcpy(test_string, token, 20);
        Array[j].name = test_string;
        token = strtok(NULL, ",");
        (Array+j)->age = atoi(token);
        token = strtok(NULL, ",");
        (Array+j)->height = atoi(token);
        token = strtok(NULL, ",");
        (Array+j)->weight = atoi(token);
        token = strtok(NULL, ",");
        free (token);
    }

    mergeSort(Array, 0, size-1);
    pntr = fopen (file_name, "w");
    for (int j = 0 ; j < size ; j ++)
    {
        fprintf(pntr, "%d, %s, %d, %d, %d\n", Array[j].id, Array[j].name,Array[j].age, Array[j].height, Array[j].weight);
    }
    free (Array);
    fclose (pntr);
}
