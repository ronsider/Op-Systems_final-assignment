#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <wait.h>

static int count_sigint=0;
static int count_sigusr=0;

void signal_handler2(int num)
{
    count_sigint++;
    printf("sigint= %d\n",count_sigint);
    fflush(stdout);

}
void signal_handler10(int num)
{
    count_sigusr++;
    printf("sigusr= %d\n",count_sigusr);
    fflush(stdout);

}

int main()
{
    while(1)
    {
    signal(SIGINT,signal_handler2);
    signal(SIGUSR1,signal_handler10);
    }
    return 0;

}
