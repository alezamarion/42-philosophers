#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#define _POSIX_C_SOURCE 200112L
#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 600

pthread_barrier_t barrier;

void* routine(void* args)
{
    while (1)
    {
        printf("Waiting at the barrier...\n");
        sleep(1);
        pthread_barrier_wait(&barrier);         //that's the point where threads will have to wait
        printf("We passed the barrier\n");
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
	pthread_t th[10];
	int i;
    pthread_barrier_init(&barrier, NULL, 10);
	for (i = 0; i < 10; i++)
    {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}
	for (i = 0; i < 10; i++) 
    {
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
    pthread_barrier_destroy(&barrier);
	return 0;
}

/*
    An barrier object stops threads execution until there are enough threads waiting.
    If there are the requested number of threads, the barrier is lifted and all threads can continue execution
*/