#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int		main(int argc, char *argv[])
{
    pthread_t   thread[4];
    int         i;
 
    //initialize mutex
    pthread_mutex_init(&mutex, NULL);

    //creates 4 threads - first loop structure
    /*
    for (i = 0; i < 4; i++)
    {
        //starts a new thread in the calling process | return 0 on success or an error number
	    if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
        {
            return 1;
        }
        printf("Thread %d has started\n", i);
 
    	//wait to finish execution
    	if (pthread_join(thread[i], NULL) != 0)
        {
            return 2;
        }
         printf("Thread %d has finished execution\n", i);
    }
    */

    //creates 4 threads - second loop structure
    for (i = 0; i < 4; i++)
    {
        //starts a new thread in the calling process | return 0 on success or an error number
	    if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
        {
            return 1;
        }
        printf("Thread %d has started\n", i);
    }
    for (i = 0; i < 4; i++)
    {
    	//wait to finish execution
    	if (pthread_join(thread[i], NULL) != 0)
        {
            return 2;
        }
         printf("Thread %d has finished execution\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
	return (0);
}

/* 
    With this first loop structure, we have one thread starting and finishing before other start executing. 
    It's not really a multithread work. Threads are not running in parallel.
    With the second loop structure, we have the expected result:

    Thread 0 has started
    Thread 1 has started
    Thread 2 has started
    Thread 3 has started
    Thread 0 has finished execution
    Thread 1 has finished execution
    Thread 2 has finished execution
    Thread 3 has finished execution
    Number of mails: 40000000

    These printed messages do not necessarily indicate that threads ended in the order described. 
    It has to do with how printf sits in the loop. One thread may terminate before another.
*/