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

//first version: here you creates the threads and then detache it, in a second version you'll create detached threads
// int     main(int argc, char *argv[])
// {
//     pthread_t thread[THREAD_NUM];
//     int     i;

//     for (i = 0; i < THREAD_NUM; i++)
//     {
//         if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
//             perror("Failed to create thread");
//         pthread_detach(thread[i]);
//     }

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
//    pthread_exit(0); //here threads can finish before main exits
//}

/*
    second version: creating detached threads from beginning, instead of changing after you create an thread
    you will use the second parameter of pthread_create(): you will need a second object, an 
    ptread_attr_t data type, and you will have to cal pthread_attr_init() and pthread_attr_setdetachstate()
    After all this, you'll have to destroy the object using pthread_attr_destroy()
    OBS: In first version, an thread can start execution and finish it before pthread_detach() is called
    So, in this second version, there is not a gap between setting a thread and detaching it
*/
int     main(int argc, char *argv[])
{
    pthread_t       thread[THREAD_NUM];
    pthread_attr_t  detached_thread;  
    int             i;

    pthread_attr_init(&detached_thread);
    pthread_attr_setdetachstate(&detached_thread, PTHREAD_CREATE_DETACHED); 

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&thread[i], &detached_thread, &routine, NULL) != 0)
            perror("Failed to create thread");
        pthread_detach(thread[i]);
    }
    pthread_attr_destroy(&detached_thread);
    pthread_exit(0);
}




/*
    pthread_detach() used when you have a long running process you want to start, inside the main thread
    but you do not want to let main thread keep on running, because it will take a long time to execute all 
    threads. So main starts threads and then forget about it.


*/
