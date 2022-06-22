#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t     mutex;

/*
    All 4 threads will start executing the same function routine(), but only one will be able to lock that mutex
    the other threads will going have to wait. Only after unlock, other thread can execute this function.
    With trylock you are trying to lock the mutex, does not mean you will got it. You should always check the return 
    of trylock.
*/

//using mutex:
// void    *routine(void *arg)
// {
//     pthread_mutex_lock(&mutex);
//     printf("Got lock\n");
//     sleep(1);
//     pthread_mutex_unlock(&mutex);
// }

//using trylock:
void    *routine(void *arg)
{
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
        printf("Didn't get lock\n");
}


int		main(int argc, char *argv[])
{
    pthread_t   thread[4];
    int            i;
    
    //creates 4 threads - second loop structure
    for (i = 0; i < 4; i++)
    {
        //starts a new thread in the calling process | return 0 on success or an error number
	    if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
            perror("Error at creating a thread");
    }
    for (i = 0; i < 4; i++)
    {
    	//wait to finish execution
    	if (pthread_join(thread[i], NULL) != 0)
            perror("Error at joining a thread");
    }
	return (0);
}