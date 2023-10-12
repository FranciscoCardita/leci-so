#include <stdio.h>
#include <stdlib.h>

#include "thread.h"

void* thread_main(void* arg)
{
    printf("N2 [10-20]: ");
    static int n2 = 0;
    scanf("%d", &n2);

    return NULL;
}

int main()
{
    printf("N1 [1-9]: ");
    static int n1;
    scanf("%d", &n1);
    if (n1 < 1 || n1 > 9)
    {
        printf("N1 should be between 1 and 9");
        exit(EXIT_FAILURE);
    }

    pthread_t thr;
    thread_create(&thr, NULL, thread_main, &n1);
    thread_join(thr, NULL);

    return 0;
}
