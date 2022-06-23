#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

// chefs = threads
// stove = shared data (+mutex)

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = { 100, 100, 100, 100 };

void* routine(void* args)
{
    for (int i = 0; i < 4; i++)
    {
        if (pthread_mutex_trylock(&stoveMutex[i]) == 0) 
        {
            int fuelNeeded = (rand() % 30);
            if (stoveFuel[i] - fuelNeeded < 0)
            {
                printf("No more fuel... going home\n");
            } 
            else 
            {
                stoveFuel[i] -= fuelNeeded;
                usleep(500000);
                printf("Fuel left %d\n", stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break;
        } 
        else
        {
            if (i == 3)
            {
                printf("No stove available yet, waiting...\n");
                usleep(300000);
                i = 0;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    pthread_t th[10];
    for (int i = 0; i < 4; i++)
        pthread_mutex_init(&stoveMutex[i], NULL);
    for (int i = 0; i < 10; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread");
    }
    for (int i = 0; i < 4; i++)
        pthread_mutex_destroy(&stoveMutex[i]);
    return 0;
}

/*
    The questions you have to ask yourself are: Can I afford to wait for the lock? 
    Is it okay if I don't obtain the lock (because I can retry later or because I have a way of doing the work 
    without needing the lock)? 
    When you answer those questions, it should be fairly clear which one you want. 
    
    Use the blocking one when you need the lock unconditionally. 
    Use the nonblocking one when you don't want to wait and have an alternative thing to do when you can't get the lock

    if pthread_mutex_trylock(&mutex) is successfull (i.e. it returns 0) then first part (i.e. critical section) 
    would be executed and function will return. 
    If pthread_mutex_trylock(&mutex) is unsuccessful(i.e. it returns -1) then else part would be executed and 
    hopefully thread busy would be printed and function would return without executing critical section.
*/