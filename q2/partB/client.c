#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <wait.h>

int main(int argc,char *argv[])
{
    int a;//parametrs check
    a=atoi(argv[2]);
 
    if(argc!=4&&(a!=2||a!=10))//1)name of executable. 2)desired id of process .3)signal number. 4).how many signals
    {
        printf("please re-check command line input validity");
        exit(0);
    }
   
    int length=atoi(argv[3]);
    for(int i=0;i<length;i++)
    {
        kill(atoi(argv[1]),a);
    }

    return 0;
}