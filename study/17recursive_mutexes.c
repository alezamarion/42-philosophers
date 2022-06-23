#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define THREAD_NUM  8
pthread_mutex_t     mutex;
int                 fuel = 50;

void    *routine(void *args)
{
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);                //here we set an deadlock
    fuel += 50;
    printf("Incremented fuel to: %d\n", fuel);
    pthread_mutex_unlock(&mutex);
}

int     main(int argc, char *argv[])
{
    pthread_t           thread[THREAD_NUM];
    int                 i;

    pthread_mutexattr_t recursive_mutex;        //set this object and functions to work with recursive mutex
    pthread_mutexattr_t_init(&recursive_mutex);
    pthread_mutexattr_settype(&recursive_mutex, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&mutex, &recursive_mutex); //you then use the second argument of pthread_mutex_init()
 
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }
    printf("Fuel: %d\n", fuel);
    pthread_mutex_destroy(&mutex);
    pthread_attr_destroy(&recursive_mutex); //you'll have to destroy this recursive mutex also
    return (0);
}
