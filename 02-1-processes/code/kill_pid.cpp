#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "process.h"

int main(void)
{
    printf("PID: ");
    u_int32_t pid;
    scanf("%d", &pid);
    pkill((pid_t)pid, SIGINT);
    return 0;
}