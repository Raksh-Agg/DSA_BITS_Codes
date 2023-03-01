#include <stdio.h>
#include <string.h>
#include <sys/time.h>
struct timeval t1,t2;
double time_taken;
int main ()
{
    char* arrPtr[20];
    char arrHard[20][50] =
    {
        "This is my dream",
        "oiorr is my dream",
        "Ahem, This is my dream",
        "For real is my dream",
        "mbkgjig is my dream",
        "fygrieuonf is my dream",
        "hehe is my dream",
        "sfhoi is my dream",
        "pekfpsfos is my dream",
        "popop is my dream",
        "trauma is my dream",
        "xnkxnskd is my dream",
        "Tsjhfushhis is my dream",
        "Cappa is my dream",
        "zmnx, is my dream",
        "fwshfowr is my dream",
        "tehma is my dream",
        "ishfois is my dream",
        "qqqTqqhis is my dream",
        "hgfyuris is my dream",
    };
    arrPtr[0] = "This is my dream";
    arrPtr[1] = "oiorr is my dream";
    arrPtr[2] = "Ahem- This is my dream";
    arrPtr[3] = "For real is my dream";
    arrPtr[4] = "mbkgjig is my dream";
    arrPtr[5] = "fygrieuonf is my dream";
    arrPtr[6] = "hehe is my dream";
    arrPtr[7] = "sfhoi is my dream";
    arrPtr[8] = "pekfpsfos is my dream";
    arrPtr[9] = "popop is my dream";
    arrPtr[10] = "trauma is my dream";
    arrPtr[11] = "xnkxnskd is my dream";
    arrPtr[12] = "Tsjhfushhis is my dream";
    arrPtr[13] = "Cappa is my dream";
    arrPtr[14] = "zmnxo is my dream";
    arrPtr[15] = "fwshfowr is my dream";
    arrPtr[16] = "tehma is my dream";
    arrPtr[17] = "ishfois is my dream";
    arrPtr[18] = "qqqTqqhis is my dream";
    arrPtr[19] = "hgfyuris is my dream";

    gettimeofday(&t1, NULL);
    char tempHard[50];
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = i ; j < 20 ; j++)
        {
            if (strcmp(arrHard[i], arrHard[j]) > 0)
            {
                strcpy(tempHard, arrHard[j]);
                strcpy(arrHard[j], arrHard[j+1]);
                strcpy(arrHard[j+1], tempHard);
            }
        }
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Taking Sum took %f seconds to execute\n", time_taken);

    gettimeofday(&t1, NULL);
    char *tempPtr;
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = i ; j < 20 ; j++)
        {
            if (strcmp(arrPtr[i], arrPtr[j]) > 0)
            {

                tempPtr = arrPtr[i];
                arrPtr[i] = arrPtr[j];
                arrPtr[j] = tempPtr;
            }
        }
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Taking Sum took %f seconds to execute\n", time_taken);
    
    
    return 0;
}