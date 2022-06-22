#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
    for (int i = 0; i < 100000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int		main(int argc, char *argv[])
{
	pthread_t	thread1;
	pthread_t	thread2;

    //initialize mutex
    pthread_mutex_init(&mutex, NULL);

	//starts a new thread in the calling process | return 0 on success or an error number
	if (pthread_create(&thread1, NULL, &routine, NULL) != 0)
        return 1;
	if (pthread_create(&thread2, NULL, &routine, NULL) != 0)
        return 2;

	//wait to finish execution
	if (pthread_join(thread1, NULL) != 0)
        return 3;
	if (pthread_join(thread2, NULL) != 0)
        return 4;
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
	return (0);
}

/*
    Without mutex:
    Sometimes the result is 20000 (correct), other times the result is another aleatory number (11987 or 11564)
    To increment a variable:
        read it
        increment it
        write in memory
    One thread get value: 23, increment 23, write in memory 24 and at some time other thread get value 23.
    Then first thread continues its job until 30
    Then second thread (that was paused by system) starts again: had read 23 and increment variable to 24.
    In this case, the variable go from 30 back to 24.
    This is an issue named race condition: you'll have an wrong result.
    In this case the thread1 10000 iterations does not finish before thread2 starts to work

    It's possible to solve this with mutex: it's kind of a lock around a section of code. In this case, you execute
    an thread and then another. It protects against other threads executing same code at same time - in this case
    routine().

    The code section where multiple threads modify the same object in the memory is called a critical section. 
    Generally, the critical section should be protected with some type of lock that would force other threads to wait
    until the current thread finishes the execution and ensures that they all get the correct incremented value. 
    Mutex is one of the lock types that can be utilized to guard an critical section like this.

    As per operating system terminology, mutexes and semaphores are kernel resources that provide synchronization 
    services (also called synchronization primitives). 

    Strictly speaking, a mutex is a locking mechanism used to synchronize access to a resource. 
    Only one task (can be a thread or process based on OS abstraction) can acquire the mutex. It means there is 
    ownership associated with a mutex, and only the owner can release the lock (mutex). 

    A mutex provides mutual exclusion, either producer or consumer can have the key (mutex) and proceed with their 
    work. As long as the buffer is filled by the producer, the consumer needs to wait, and vice versa, for example.

    A mutex is a lock. Only one state (locked/unlocked) is associated with it. 
    The programmer must unlock the mutex as many number times as it was locked. 
    
    Semaphore is signaling mechanism (“I am done, you can carry on” kind of signal). For example, if you are listening
    to songs (assume it as one task) on your mobile phone and at the same time, your friend calls you, an interrupt 
    is triggered upon which an interrupt service routine (ISR) signals the call processing task to wakeup. 

*/