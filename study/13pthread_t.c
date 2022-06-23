#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 2

void    *routine(void *args)
{
    //another way to get pthread_t number id
    pthread_t thread = pthread_self();
    printf("%ul\n", thread);
}


int     main(int argc, char *argv[])
{
    pthread_t thread[THREAD_NUM];
    int     i;

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
        printf("%ul\n", thread[i]);
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
            perror("Failed to join thread");
    }
    return (0);
}

/*
    If you "printf("%ul\n", thread[i]);" you will get two numbers that identifies both threads. This are create during
    pthread_create call.
    So, an pthread_t type will store pthreads id number.
    You can also use pthread_self() function to get pthread number id.
    It's not a good practice to work with pthread_t values: pthread_t have to be treated as an opaque data type, meaning
    that it's not always garanteed that it's going to be of unsigned long type, it might be an unsigned long long or an 
    integer or a character or even an structure that has certain members.

    You could use #include <sys/syscall.h> and gettid() to get thread id:
    printf("%d\n", (pid_t) syscall(SYS_gettid));
    But it only work on linux, and it is the internal thread id inside the OS, does not have anything to do with pthread_t 
    (this works above OS)
*/