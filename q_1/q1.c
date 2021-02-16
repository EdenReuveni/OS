#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. global bss (block started by symbol), uninitialized data */
int primes[] = { 2, 3, 5, 7 };  /* 2. global data */

static int
square(int x)                   /* 3. local text */
{
    int result;                 /* 4. stack */

    result = x * x;
    return result;              /* 5. moves from stack register (rbp) to accumulate register (eax) */
}

static void
doCalc(int val)                 /* 6. local text */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7.  theory: stack, actual: undefined*/

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* 8. global text */
{
    static int key = 9973;      /* 9. local data */
    static char mbuf[10240000]; /* 10. local bss */
    char* p;                    /* 11.  theory: stack, actual: undefined */


    doCalc(key);

    exit(EXIT_SUCCESS);
}
