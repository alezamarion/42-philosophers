#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void    *roll_dice()
{
    int value = (rand() % 6) + 1;
    printf("%d\n", value);

}

//Thread will roll a dice and return a result. Main function will print this result.
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