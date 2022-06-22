/*
    Create 10 threads, each one taking a unique prime from the primes array and print it on the screen
    https://www.youtube.com/watch?v=HDohXvS6UIk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=9
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int     primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

int     main(int argv, char *argc[])
{
    pthread_t   thread[10];

    for (int i = 0; i < 10; i++)
    {
        if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }


    return (0);
}















