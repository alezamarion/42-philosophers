#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define THREAD_NUM 2

void    *routine(void *args)
{
    sleep(1);
    printf("Finished execution\n");
}

int     main(int argc, char *argv[])
{
    pthread_t thread[THREAD_NUM];
    int     i;

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
        pthread_detach(thread[i]);
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }
    return (0);
}
