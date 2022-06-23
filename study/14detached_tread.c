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

/*  when you use pthread_detach, you do not need to use pthread_join, makes no sense
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }
    
    instead of using return(0), you use pthread_exit(0): using return(0), threads are on sleep(1) and the main terminates, so 
    the threads are killed
    return (0);
*/
    pthread_exit(0); //here threads can finish before main exits
}

/*
    pthread_detach() used when you have a long running process you want to start, inside the main thread
    but you do not want to let main thread keep on running, because it will take a long time to execute all 
    threads. So main starts threads and then forget about it.


*/
