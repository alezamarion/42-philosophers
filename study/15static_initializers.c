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

    //if you use this macro, you do not need to initializa your mutex
    //but if you are initializing an array of threads, you will have to iterate it assigning this macro,
    //specially if you dinamically allocates the threads
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    //pthread_mutex_init(&mutex, NULL);

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
    //if you use macro above, it's a good practive keep using pthread_mutex_destroy, some systems clean threads
    //automaticaly, others does not.
    pthread_mutex_destroy(&mutex);
    return (0);
}
