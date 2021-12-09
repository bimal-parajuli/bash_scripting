#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void func1(void *ptr);
void func2(void *ptr);

sem_t mutex;
char buff[100];

int main(int argc, char *argv[])
{
    pthread_t thread1;
    pthread_t thread2;

    char *message1 = "Inside first thread";
    char *message2 = "Inside Second thread";

    sem_init(&mutex, 0, 1);

    pthread_create(&thread1, NULL, (void *)&func1, (void *)message1);
    pthread_create(&thread2, NULL, (void *)&func2, (void *)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&mutex);
    return 0;
}

void func1(void *ptr)
{

    char *str = (char *)ptr;

    // Just added this line to control the flow of threads.
    sleep(1.000001);

    printf("%s\n", str);

    // Critical Section...
    sem_wait(&mutex);
    sprintf(buff, "%s", "LOL");
    sem_post(&mutex);
    // End of Critical Section...

    pthread_exit(0);
}

void func2(void *ptr)
{
    char *str = (char *)ptr;

    printf("%s\n", str);

    // Just added this line to control the flow of threads.
    sleep(2.000001);

    // Critical Section...
    sem_wait(&mutex);
    printf("%s ", buff);
    sem_post(&mutex);
    // End of Critical Section...

    pthread_exit(0);
}
