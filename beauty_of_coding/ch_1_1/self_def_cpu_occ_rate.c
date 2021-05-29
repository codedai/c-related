#include <stdio.h>
#include <pthread.h>
#include <time.h>

const int CPUNUM = 8;
int busy_time, idle_time;

void dead_loop(void);
void sleep_ms(long milliseconds);

int main(void) {
    float percent;
    printf("Enter the target percentage (in float, e.g. 0.35): ");
    scanf("%f", &percent); // Get the rate from stander input.

    /* Calculate the time parameters */
    int total_time = 500;
    busy_time = (int) total_time * percent;
    idle_time = total_time - busy_time;

    /* Create multi-threads */
    pthread_t thread[CPUNUM-1];
    for (int i = 0; i < CPUNUM - 1; i++)
        pthread_create(&thread[i], NULL, dead_loop, NULL);
    dead_loop();
    pthread_join(thread[0], NULL);
    return 1;
}

void sleep_ms(long milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

void dead_loop(void) {
    static __thread clock_t start;
    while(1) {
        start = clock();
        while ((clock() - start) / CLOCKS_PER_SEC * 1000 < busy_time)
            ;
        sleep_ms(idle_time);
    }
}
