#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "delays.h"
#include "process.h"

int main(void)
{
    pid_t ret =  pfork();

    for (u_int32_t i = 1; i <= 20; i++)
    {
        if (ret == 0 && i <= 10)
            printf("I'm the child: %d\n", i);
        else if (ret != 0 && i > 10)
        {
            usleep(2000);
            printf("I'm the parent: %d\n", i);
        }            
    }    
}