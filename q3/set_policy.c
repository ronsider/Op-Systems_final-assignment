#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <errno.h>
/*In today's kernel only the Real Time 
Scheduling policies allow setting of sched_priority -
 it is always 0 for the non-RT policies (SCHED_OTHER, SCHED_BATCH, and SCHED_IDLE).<==stakoverflow*/



 int main(int argc, char *argv[]) 
 { 
     if(argc!=3)//1)executable. 2)which policy. 3)priority number
     {
         printf("desired input is wrong please re-enter\n");
         exit(0);
         
     }
 
 int policy_number = atoi(argv[1]);
 int priority = atoi(argv[2]);
 
pid_t getpid();//get current process id
struct sched_param pts=//pass this as parameter to setschduler
{
    .sched_priority=priority
};

int p=sched_getscheduler(getpid());
if(p==SCHED_RR)
{
    printf("recieved SCHED_RR policy\n");
}
else if(p==SCHED_FIFO)
{
    printf("recieved SCHED_FIFO policy\n");

}
else if(p==SCHED_OTHER)
{
    printf("recieved SCHED_OTHER policy\n");

}
else
{
    printf("undefined or non real time scheduling received\n");
}
switch ((sched_setscheduler(getpid(),policy_number,&pts)))
{
case EINVAL:
    printf("pid is negative or non recognized policy\n");
    break;
    case EPERM:
    printf("thread has no appropriate privileges\n");
    break;
    case ESRCH:
    printf("process with this pid couldnt be found\n");//taken from linux manual but non likely to happen because we use getpid()
    break;
    case 0:
    printf("scheduling policy set succsefully\n");
    break;

default:
    printf("no errors accured\n");
}

switch (sched_getscheduler(getpid()))
{
case SCHED_OTHER: 
    printf("recieved SCHED_OTHER policy\n");
    break;
case SCHED_RR:  
    printf("recieved SCHED_RR policy\n"); 
    break;
case SCHED_FIFO:  
    printf("recieved SCHED_FIFO policy\n");
     break;

default:
    printf("eror or odd behaviour please try re run the prgram\n");
}


return 0;
}