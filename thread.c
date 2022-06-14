#include <stlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*routine()
{
	printf("Test from threads\n");
}

int		main(int argc, char *argv[])
{
	pthread_t	thread1;

	//to initialize an thread
	pthread_create();
	return (0);
}


//para compilar: gcc -g -pthread thread.c -o thread