#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//first version: one mutex
/*
#define THREAD_NUM  8
pthread_mutex_t     mutex;
int                 fuel = 50;

void    *routine(void *args)
{
    pthread_mutex_lock(&mutex);
    fuel += 50;
    printf("Incremented fuel to: %d\n", fuel);
    pthread_mutex_unlock(&mutex);
}

int     main(int argc, char *argv[])
{
    pthread_t       thread[THREAD_NUM];
    int             i;

    pthread_mutex_init(&mutex, NULL);
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
    return (0);
}
*/

//second version: more than one mutex

#define THREAD_NUM  8
pthread_mutex_t     mutex_fuel;
int                 fuel = 50;
pthread_mutex_t     mutex_water;
int                 water = 50;

void    *routine(void *args)
{
    pthread_mutex_lock(&mutex_fuel);
    pthread_mutex_lock(&mutex_water);
    fuel += 50;
    water = fuel;
    printf("Incremented fuel to: %d, set water to %d\n", fuel, water);
    pthread_mutex_unlock(&mutex_fuel);
    pthread_mutex_unlock(&mutex_water);
}

int     main(int argc, char *argv[])
{
    pthread_t       thread[THREAD_NUM];
    int             i;

    pthread_mutex_init(&mutex_fuel, NULL);
    pthread_mutex_init(&mutex_water, NULL);
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
    printf("Fuel: %d   Water: %d\n", fuel, water);
    pthread_mutex_destroy(&mutex_fuel);
    pthread_mutex_init(&mutex_water, NULL);
    return (0);
}


