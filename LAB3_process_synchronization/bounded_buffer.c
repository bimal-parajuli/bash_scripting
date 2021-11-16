#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

// Bounded Buffer size
#define maxSize 10

// number of buffer accesses
#define max_access 4

//To calculate the greater of two numbers.
#define max(a, b) ((a > b) ? (a) : (b))

sem_t empty;           // num of empty items
sem_t full;            // num of full items
pthread_mutex_t mutex; // mutex from 'pthread.h'

int buff[maxSize]; // circular array
int rear, front;   // counters of buffer

// function creates a Producer thread
void *Producer(void *id)
{
    int pid = *((int *)id);
    int item;
    // printf("Created producer thread with id %d\n", *((int*) id) );

    for (int i = 0; i < max_access; i++)
    {

        // entry section
        sem_wait(&empty); // process is kept waiting if buffer is full

        // locking the mutex
        pthread_mutex_lock(&mutex);

        // critical section of Producer process

        item = rand(); // take a random value
        buff[rear] = item;

        printf("Producer %d : produced %d\n", pid, item);
        rear = (rear + 1) % maxSize; // update rear

        // exit section
        pthread_mutex_unlock(&mutex); // unlocking the mutex

        sem_post(&full); // since item has been produced full has increased
    }
}

// function creates a Consumer thread
void *Consumer(void *id)
{
    int pid = *((int *)id);

    for (int i = 0; i < max_access; i++)
    {

        // entry section
        sem_wait(&full); // Consumer process is kept waiting if buffer has no items

        // locking the mutex
        pthread_mutex_lock(&mutex);

        // critical section of Consumer process

        int tmp = buff[front];
        front = (front + 1) % maxSize; // update front to next item

        printf("Consumer %d : consumed %d\n", pid, buff[front]);

        // exit section
        pthread_mutex_unlock(&mutex); // unlocking the mutex
        sem_post(&empty);             // since one buffer item has been consumed
    }
}

/* This function creates the threads and the mutexes to demonstrate the implementation
  of the bounder buffer or producer consumer problem*/
void bounded_buffer(int no_prod, int no_cons)
{

    int highid = max(no_prod, no_cons);
    int process_id[highid]; // to store id of thread to be sent as an argument

    // user threads
    pthread_t producers[no_prod], consumers[no_cons];

    printf("Number of producer process :: %d\n", no_prod);
    printf("Number of consumer process :: %d\n\n", no_cons);

    // global vals init
    front = rear = 0;

    // initialize semaphores
    sem_init(&empty, 0, maxSize);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // creating new producer threads
    for (int i = 0; i < no_prod; i++)
    {
        process_id[i] = i + 1;
        pthread_create(producers + i, NULL, &Producer, (void *)&process_id[i]);
    }

    // creating new Consumer threads
    for (int i = 0; i < no_cons; i++)
    {
        process_id[i] = i + 1;
        pthread_create(consumers + i, NULL, &Consumer, (void *)&process_id[i]);
    }

    // joining producer threads
    for (int i = 0; i < no_prod; i++)
    {
        pthread_join(producers[i], NULL);
    }

    // joining consumer threads
    for (int i = 0; i < no_cons; i++)
    {
        pthread_join(consumers[i], NULL);
    }

    // destroying semaphores
    sem_close(&empty);
    sem_close(&full);
    pthread_mutex_destroy(&mutex);

    return;
}

int main(int argc, char **argv)
{

    printf("One producer and one consumer process.\n\n");
    bounded_buffer(1, 1);

    printf("\nMultiple producer process and consumer processes \n\n");
    bounded_buffer(5, 4);

    return 0;
}
