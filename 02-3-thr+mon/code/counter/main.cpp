#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "thread.h"

static int n1;

void* thread_main(void* arg)
{
    printf("N2 [10-20]: ");
    int n2 = 0;
    scanf("%d", &n2);

    if (n2 < 10 || n2 > 20)
    {
        printf("N2 should be between 10 and 20\n");
        exit(EXIT_FAILURE);
    }
    
    printf("(child) %d\n", n1);
    usleep(500000);
    while (n1 < n2)
    {
        n1++;
        printf("(child) %d\n", n1);
        usleep(500000);
    }
    n1--;
    return NULL;
}

int main()
{
    printf("N1 [1-9]: ");
    scanf("%d", &n1);

    if (n1 < 1 || n1 > 9)
    {
        printf("N1 should be between 1 and 9\n");
        exit(EXIT_FAILURE);
    }

    pthread_t thr;
    thread_create(&thr, NULL, thread_main, &n1);
    thread_join(thr, NULL);

    while (n1 >= 1)
    {
        printf("(parent) %d\n", n1);
        usleep(500000);
        n1--;
    }    

    return 0;
}
