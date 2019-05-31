#include "semaphore.h"

int main(void)
{
    for (;;)
    {
        init_semaphore(7);
        up(1);
        down(1);
    }
    return 0;
}
