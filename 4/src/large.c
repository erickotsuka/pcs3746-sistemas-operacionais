#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MEMORY_SIZE	        (64 * 1024 * 1024)
#define MEMORY_USED         (MEMORY_SIZE / 3)

static unsigned char m[MEMORY_USED];

void do_write(unsigned char *p, size_t length)
{
	for (size_t i = 0; i < length; i++)
		p[i] = rand() & 0xFF;
}

int main(void)
{
    do_write(m, sizeof(m));

    for (;;);

	return 0;
}
