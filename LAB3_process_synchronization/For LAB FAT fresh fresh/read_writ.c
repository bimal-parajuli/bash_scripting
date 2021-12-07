#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>

#define max(a, b) (( (a) > (b)) ? (a) : (b))

// number of accesses to shared memory 
#define accesses 4

// semaphores
sem_t wrt;
pthread_mutex_t mutex;

// global variable to store number of readers and writers
int nwrit, nread;

int svar; // shared variable

// waiting readers and writer
int rcount, wcount;


// function creates a Writer process 
void *Writer(void *id){
    int pid = *((int*) id);

    for(int i = 0; i < accesses; i++){

        // entry section acquiring the write lock
        sem_wait(&wrt);

        // critical section writing to shared variable
        svar += pid;

        printf("Writer '%d': writes '%d'\n", pid, svar);

        sem_post(&wrt);       
    }
}


// function creates a Reader process
void *Reader(void *id){
    int pid = *((int*) id);

    for(int i = 0; i < accesses; i++){   
        // acquire lock before entering critical section
        pthread_mutex_lock(&mutex);

        // updating num of readers
        rcount++;

        // so check for active or waiting writers
        if(rcount == 1){
            // wait writers until readers are present
            sem_wait(&wrt);
        }
        
        // reader exits CS for other reader to enter
        pthread_mutex_unlock(&mutex);

        // reading
        printf("Reader '%d': reads '%d'\n", pid, svar);

        // acquire lock before entering CS to exit
        pthread_mutex_lock(&mutex);

        // exit sec
        rcount--; // decrease num of readers

        if(rcount == 0){ // no readers reading
            sem_post(&wrt); // allow writers to write

        }

        pthread_mutex_unlock(&mutex); // allow other user to enter cs
    }   
}


int main(int argc, char **argv){
    nwrit = 2;
    nread = 5;

    // user threads
    pthread_t readers[nread], writers[nwrit];

    int _maxid = fmax(nread, nwrit); // i.e. stores the maximum number of processes
    int pids[_maxid]; // to store id of thread to be sent as an argument


    // user inputs we got for the problem
    printf("\nThe number of readers :: %d\n", nread);
    printf("\nThe number of writers :: %d\n", nwrit);

    printf("\nThe maximum number of time a producer can produce or a consumer can consume an item :: %d\n\n", accesses);

    // initialize semaphores
    rcount = 0;
    svar = 0;
    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);


    // creating new Reader and Writer threads
    for(int i = 0; i < nwrit; i++){
        pids[i] = i + 1;
        pthread_create(writers + i, NULL, &Writer, &pids[i]);
    }

    for(int i = 0; i < nread; i++){
        pids[i] = i + 1;

        pthread_create(readers + i, NULL, &Reader, &pids[i]);
    }


    // joining Reader threads 
    for(int i = 0; i < nread; i++){
        pthread_join(readers[i], NULL);
    }

    // joining Writer threads 
    for(int i = 0; i < nwrit; i++){
        pthread_join(writers[i], NULL);
    }

    // destroying semaphores
    sem_close(&wrt);
    pthread_mutex_destroy(&mutex);
}
