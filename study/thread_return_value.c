#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>


/*  first version: here we print the result from our thread

void    *roll_dice()
{
    int value = (rand() % 6) + 1;
    printf("%d\n", value);

}

//thread will roll a dice and return a result. Main function will print this result.
int     main(int argc, char *argv[])
{
    pthread_t   thread;

    srand(time(NULL));
    if (pthread_create(&thread, NULL, &roll_dice, NULL) != 0)
    {
        return (1);
    }
    if (pthread_join(thread, NULL) != 0)
    {
        return (2);
    }
    return (0);
}
*/

//second version: here we get the result from our thread to main function and print it from main

void    *roll_a_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    printf("Thread result:  %p\n", result);
    return (void*) result;
}

int     main(int argc, char *argv[])
{
    int         *result;
    pthread_t   thread;
   
    srand(time(NULL));
    if (pthread_create(&thread, NULL, &roll_a_dice, NULL) != 0)
    {
        return (1);
    }
    if (pthread_join(thread, (void**) &result) != 0)
    {
        return (2);
    }
    //just to check that we are dealing with the same memory location of line 39
    printf("Main result:    %p\n", result);
  
    //as long we are getting result from a thread to main function, we have to print it
    printf("Result: %d\n", *result);
    
    //and we have to free it
    free(result);
 
    return (0);
}

/*
    Check the full explanation here:
    https://www.youtube.com/watch?v=ln3el6PR__Q&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=6
    CodeVault Rocks!

    In the second version we get the value from a thread function (roll_a_dice) to the main function.
    We use the second parameter of pthread_join(). This parameter is a double void pointer because the third
    parameter of pthread_create() expects a void pointer and (#) (see bellow).




    -> int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *), void *restrict arg);

    The pthread_create() function starts a new thread in the calling process.  The new thread starts 
    execution by invoking start_routine(); arg is passed as the sole argument of start_routine().

    The new thread terminates in one of the following ways:

    * It calls pthread_exit(3), specifying an exit status value that is available to another thread in 
    the same process that calls pthread_join(3).

    * It returns from start_routine().  This is equivalent to calling pthread_exit(3) with the value supplied 
    in the return statement.

    * It is canceled (see pthread_cancel(3)).

    * Any of the threads in the process calls exit(3), or the main thread performs a return from main().  
    This causes the termination of all threads in the process.

    -> int pthread_join(pthread_t thread, void **retval);

    The pthread_join() function waits for the thread specified by thread to terminate. If that thread has 
    already terminated, then pthread_join() returns immediately. The thread specified by thread must be joinable.

    (#) If retval is not NULL, then pthread_join() copies the exit status of the target thread (i.e., the value that
        the target thread supplied to pthread_exit(3)) into the location pointed to by retval.  If the target thread 
        was canceled, then PTHREAD_CANCELED is placed in the location pointed to by retval.

    If multiple threads simultaneously try to join with the same thread, the results are undefined.  If the thread
    calling pthread_join() is canceled, then the target thread will remain joinable (i.e., it will not be detached).
*/


