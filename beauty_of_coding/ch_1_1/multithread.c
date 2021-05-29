#include <stdio.h>
#include <pthread.h>

const int CPUNUM = 4;

void dead_loop(void) {
    while(1)
        ;
}

int main(void) {
    pthread_t thread[CPUNUM];
    for (int i = 0; i < CPUNUM; i++) 
        pthread_create(&thread[i], NULL, dead_loop, NULL);
    pthread_join(thread[0], NULL);
    printf("Program Ends.");
}
