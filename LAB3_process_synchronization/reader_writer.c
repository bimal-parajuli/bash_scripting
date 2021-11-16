#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
// #include <sys/wait.h>
#include <stdlib.h>

sem_t semaph_var;
pthread_mutex_t mutex;
int variable = 1;
int numreader = 0;

void *writer(void *wno)
{
    sem_wait(&semaph_var);
    variable = variable + 20;
    printf("Writer %d modified variable to %d\n", (*((int *)wno)), variable);
    sem_post(&semaph_var);
}
void *reader(void *rno)
{
    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
    {
        sem_wait(&semaph_var); // If this id the first reader, then it will block the writer
    }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    printf("Reader %d: read variable as %d\n", *((int *)rno), variable);

    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
    {
        sem_post(&semaph_var); // If this is the last reader, it will wake up the writer.
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{

    pthread_t read[2], write[2];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semaph_var, 0, 1);

    int a[10] = {1, 2}; //Just used for numbering the producer and consumer

    for (int i = 0; i < 2; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(read[i], NULL);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaph_var);

    return 0;
}