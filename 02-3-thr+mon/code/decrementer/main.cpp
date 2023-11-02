#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "thread.h"

static int cnt;
static int THREADS = 2;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t is_odd = PTHREAD_COND_INITIALIZER;
static pthread_cond_t is_even = PTHREAD_COND_INITIALIZER;

struct threadArgs {
  int id;
};

void* thread_main(void* args) {
  threadArgs* thr_args = (threadArgs*) args;
  int id = thr_args->id;

  while (true) {
    mutex_lock(&mtx);

    if (id % 2 == 0) {
      while (cnt % 2 != 0) {
        cond_wait(&is_even, &mtx);
      }
    } else {
      while (cnt % 2 == 0) {
        cond_wait(&is_odd, &mtx);
      }
    }

    cnt--;

    printf("Child %u: %d\n", (int)pthread_self(), cnt);
    usleep(500000);

    if (id % 2 == 0) {
      cond_broadcast(&is_odd);
    }
    else {
      cond_broadcast(&is_even);
    }

    if (cnt == 1 || cnt == 2) {
      mutex_unlock(&mtx);
      break;
    }

    mutex_unlock(&mtx);
  }  
  return NULL;
}

int main() {
  printf("Value [10-20]: ");
  scanf("%d", &cnt);

  if (cnt < 10 || cnt > 20) {
    printf("Value should be between 10 and 20.\n");
    exit(EXIT_FAILURE);
  }

  pthread_t thr[THREADS];

  for (int i = 0; i < THREADS; i++) {
    threadArgs* args = new threadArgs;
    args->id = i;

    thread_create(&thr[i], NULL, thread_main, (void*) args);
  }

  for(int i = 0; i < THREADS; i++) {
    thread_join(thr[i], NULL);
  }

  mutex_destroy(&mtx);
  cond_destroy(&is_even);
  cond_destroy(&is_odd);
}
