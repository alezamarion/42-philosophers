/*
    Create 10 threads, each one taking a unique prime from the primes array and print it on the screen
    https://www.youtube.com/watch?v=HDohXvS6UIk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=9
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int     primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

/*
the "void *arg" is the same of the fourth argument of pthread_create() It passes a position in memory 
to the routine() function. In this case, a pointer to the index we want to print
*/

/*
//first version: with bug :(
void    *routine(void *arg)
{
    int index = *(int*)arg;
    printf("%d ", primes[index]);

}

int     main(int argv, char *argc[])
{
    pthread_t   thread[10];

    for (int i = 0; i < 10; i++)
    {
        if (pthread_create(&thread[i], NULL, &routine, &i) != 0)
            perror("Failed to create thread");
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }
    return (0);
}
*/

//second version: OK :D
void    *routine(void *arg)
{
    int index = *(int *)arg;
    printf("%d ", primes[index]);
    free(arg);
}

int     main(int argv, char *argc[])
{
    pthread_t   thread[10];
    int         i;

    for (int i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&thread[i], NULL, &routine, a) != 0)
            perror("Failed to create thread");
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }
    return (0);
}

/*
    First version:
    The result is strange and changes every time, ex:
    7 17 19 19 19 19 23 23 0 0 or 0 0 0 0 0 0 0 0 0 0 (in this case, i = 10)
    The problem is we are passing memory addresses instead of just values
    Between the moment the thread is created and started, the value inside the memory address we are referencing
    has changed. So when a thread starts functioning, the value of "i" has changed.

    An soluction in to allocate some memory to i, for each thread
    You dealocate it inside routine() function

    Another soluction is to pass address of position in array: "primes + i" 
*/













