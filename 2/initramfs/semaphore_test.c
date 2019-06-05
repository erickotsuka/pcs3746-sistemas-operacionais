#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "semaphore.h"

#define CONSUMING_TIME_S (5)
#define PRODUCING_TIME_S (1)

#define MAX_PRODUCTS (10)

int main(void)
{
    int full = init_semaphore(0);
    int empty = init_semaphore(MAX_PRODUCTS);
    int mutex = init_semaphore(1);

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid)
    {
        /* Producer code */
        for (;;)
        {
            sleep(PRODUCING_TIME_S);
            printf("producer: Produced item\n");
            down(empty);
            down(mutex);
            printf("producer: Inserted item in buffer\n");
            up(mutex);
            up(full);
        }
    }
    else
    {
        /* Consumer code */
        for (;;)
        {
            down(full);
            down(mutex);
            printf("consumer: Removed item from buffer\n");
            up(mutex);
            up(empty);
            sleep(CONSUMING_TIME_S);
            printf("consumer: Consumed item\n");
        }
    }

    return 0;
}
