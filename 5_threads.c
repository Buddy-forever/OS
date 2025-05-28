#include <stdio.h>
#include <pthread.h>

void* run(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, run, NULL);
    pthread_join(t, NULL);
    printf("Hello from main!\n");
    return 0;
}



/*
Output:
Hello from thread!
Hello from main!
*/
