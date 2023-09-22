#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "delays.h"
#include "process.h"

int main(void)
{
    pid_t ret =  pfork();

    if (ret == 0)
    {
        for (int i = 1; i <= 10; i++)
            printf("I'm the child: %d\n", i);
    } else
    {
        pwait(NULL);
        for (int i = 11; i <= 20; i++)
            printf("I'm the parent: %d\n", i);
    }  
}