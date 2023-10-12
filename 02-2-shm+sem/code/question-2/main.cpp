#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "process.h"

int main(void)
{
    u_int32_t shmid = pshmget(IPC_PRIVATE, sizeof(u_int32_t), 0600 | IPC_CREAT | IPC_EXCL);
    u_int32_t *pcounter = (u_int32_t *)pshmat(shmid, NULL, 0);
    *pcounter = 0;

    if(pfork() == 0)
    {
        printf("Max value [10:20]: ");
        u_int32_t max;
        scanf("%d", &max);

        if (max < 10 || max > 20)
            exit(EXIT_FAILURE);
        
        while (*pcounter < max)
        {
            (*pcounter)++;
            printf("(child) %d\n", *pcounter);
            usleep(500000);
        }
        exit(EXIT_SUCCESS);
    } else
    {
        pwait(NULL);

        while (*pcounter > 1)
        {
            (*pcounter)--;
            printf("(parent) %d\n", *pcounter);
            usleep(500000);
        }        
    }
    pshmdt(pcounter);
    pshmctl(shmid, IPC_RMID, NULL);
}