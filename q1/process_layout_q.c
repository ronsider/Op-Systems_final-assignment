#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1.BSS uninitialized data segment */
int primes[] = { 2, 3, 5, 7 };  /* 2.Data initialized data segment */

static int
square(int x)                   /* 3.stack frame */
{
    int result;                 /* 4.stack frame*/

    result = x * x;
    return result;              /* 5.passed via register */
}

static void
doCalc(int val)                 /* 6.stack frame */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7.stack frame*/

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /*stack frame*/
{
    static int key = 9973;      /* Data initialized data segment */
    static char mbuf[10240000]; /* Bss unitialized data segment*/
    char* p;                    /*stack frame*/


    doCalc(key);

    exit(EXIT_SUCCESS);
}