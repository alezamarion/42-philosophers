#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void	*routine()
{
    for (int i = 0; i < 10000; i++)
    {
        mails++;
    }
}

int		main(int argc, char *argv[])
{
	pthread_t	thread1;
	pthread_t	thread2;

	//starts a new thread in the calling process | return 0 on success or an error number
	if (pthread_create(&thread1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
	if (pthread_create(&thread1, NULL, &routine, NULL) != 0)
    {
        return 2;
    }
	
	//wait to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

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
    an thread and then another.

*/