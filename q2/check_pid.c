#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if(argc!=2)//only 1 parameter is passed in command line
    {
        printf("supply only 1 number \n");
        exit(0);
        
    }
    pid_t pid;
    pid=atoi(argv[1]);
    kill(pid,0);
    if(errno==ESRCH)
    {
        printf("process %d doesn't exist\n",pid);
        exit(0);
    }
    else if(errno==EPERM)
    {
        printf("process %d exists but we have no premission\n",pid);
        exit(0);
    }
    else
    {
        printf("process %d exists\n",pid);
        exit(0);
    }
    

  
  
}
