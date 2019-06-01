#include <stdio.h>
#include <unistd.h>

#include "semaphore.h"

int main(void)
{
    int semaphore_id = init_semaphore(1);
    pid_t pid_a = fork();
    if (pid_a == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid_a)
    {
       for (;;)
       {
           printf("A\n");
           down(semaphore_id);
           sleep(1);
       }
    }
    else
    {
        for (;;)
        {
            printf("B\n");
            up(semaphore_id);
            sleep(4);
        }
    }

    return 0;
}
