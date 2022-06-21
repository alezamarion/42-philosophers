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
    {
        return 1;
    }
	if (pthread_create(&thread2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }

	//wait to finish execution
	if (pthread_join(thread1, NULL) != 0)
    {
        return 3;
    }
	if (pthread_join(thread2, NULL) != 0)
    {
        return 4;
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
	return (0);
}
