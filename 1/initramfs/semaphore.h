#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/wait.h>

#define __NR_init_semaphore	404
#define __NR_up	405
#define __NR_down 406
#define __NR_sem_debug 407

long init_semaphore(int initial_counter)
{
	return syscall(__NR_init_semaphore, initial_counter);
}

long up(int sem_id)
{
	return syscall(__NR_up, sem_id);
}

long down(int sem_id)
{
	return syscall(__NR_down, sem_id);
}
