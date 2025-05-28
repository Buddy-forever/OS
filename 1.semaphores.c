#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void* task(void* id) {
    sem_wait(&mutex);
    printf("Thread %d in critical section\n", *(int*)id);
    sem_post(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, task, &id1);
    pthread_create(&t2, NULL, task, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    return 0;
}

/*
Output:
Thread 1 in critical section
Thread 2 in critical section
*/
