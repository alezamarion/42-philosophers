#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*routine()
{
	//threads have same process id, processes have different pids
	printf("Test from threads, process id: %d\n", getpid());
	sleep(3);
	printf("Ending thread\n");
}

int		main(int argc, char *argv[])
{
	pthread_t	thread1;
	pthread_t	thread2;

	//starts a new thread in the calling process | return 0 on success or an error number
	pthread_create(&thread1, NULL, &routine, NULL);
	pthread_create(&thread1, NULL, &routine, NULL);
	
	//wait to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return (0);
}

/*
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

Compile and link with -pthread

The pthread_create() function starts a new thread in the calling process.  
The new thread starts execution by invoking start_routine(); arg is passed as the sole argument of start_routine().

The attr argument points to a pthread_attr_t structure whose contents are used at thread creation time to determine  attributes  for  the  new
    thread;  this structure is initialized using pthread_attr_init(3) and related functions.  If attr is NULL, then the thread is created with de‐
    fault attributes.

Before returning, a successful call to pthread_create() stores the ID of the new thread in the buffer pointed to by thread; this identifier is
    used to refer to the thread in subsequent calls to other pthreads functions.

gcc -g -pthread thread.c -o thread

On most systems that use stabs format, -g enables use of extra debugging information that only GDB can use; 
this extra information makes debugging work better in GDB but will probably make other debuggers crash or refuse to read the program. 
If you want to control for certain whether to generate the extra information, use -gstabs+, -gstabs, -gxcoff+, -gxcoff, or -gvms

1 - Processes can contain multiple threads. Threads have same IDs.
	A single process can have multiple threads.
2 - Address space: With threads all variables are in same space. All threads can access all variables.
	Forking duplicates every variables to the child processes. You can modify then individually.
	Threads have shared memory, if you modify an variable, it happens in all threads from the same calling process.




*/