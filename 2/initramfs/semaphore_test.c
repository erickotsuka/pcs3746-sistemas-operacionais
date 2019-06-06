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
            printf("producer: Begin\n");
            sleep(PRODUCING_TIME_S);
            printf("\nproducer: Produced item\n");
            down(empty);
            down(mutex);
            printf("\nproducer: Start critical region\n");
            printf("producer: Inserted item in buffer\n");
            printf("producer: End critical region\n");
            up(mutex);
            up(full);
            printf("producer: End\n");
        }
    }
    else
    {
        /* Consumer code */
        for (;;)
        {
            printf("consumer: Begin\n");
            down(full);
            down(mutex);
            printf("\nconsumer: Start critical region\n");
            printf("consumer: Removed item from buffer\n");
            printf("consumer: End critical region\n");
            up(mutex);
            up(empty);
            sleep(CONSUMING_TIME_S);
            printf("consumer: Consumed item\n");
            printf("consumer: End\n");
        }
    }

    return 0;
}
