#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "thread.h"

void* thread_main(void * arg)
{
    printf("[thread_main] start\n");
    usleep(500000);
    printf("[thread_main] end\n");
    return NULL;
}

int main()
{
    pthread_t thr;
   
    printf("[main] start\n");
    thread_create(&thr, NULL, thread_main, NULL);
    thread_join(thr, NULL);
    printf("[main] end \n");

    return 0;
}
