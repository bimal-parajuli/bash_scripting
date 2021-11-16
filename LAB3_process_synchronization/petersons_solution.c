#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

bool flag[2];
int numInt, turn, total_value;
void *process1(void *ptr1)
{
    int k = 0;
    int numInt = 0;

    while (k < 100000)
    {
        flag[0] = true;
        turn = 1;

        while (flag[1] && turn == 1)
            ;

        if (turn == 0)
            numInt++;
        total_value = total_value + 1;

        flag[0] = false;
        k++;
    }
    printf("From process1 total = %d\n", total_value);
    printf("Process2 interrupted %d times in critical section by Process 1.\n", numInt);
}

void *process2(void *ptr2)
{
    int k = 0;
    int numInt = 0;

    while (k < 100000)
    {
        flag[1] = true;
        turn = 0;

        while (flag[0] && turn == 0)
            ;

        if (turn == 1)
            numInt++;
        total_value = total_value + 1;

        flag[1] = false;
        k++;
    }

    printf("From process2 total = %d\n", total_value);
    printf("Process1 interrupted %d times in critical section by Process 2.\n", numInt);
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, process1, (void *)0);
    pthread_create(&t2, NULL, process2, (void *)1);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


