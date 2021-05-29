#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define GAP 200
#define CPUNUM 8

int busy_time[GAP], idle_time[GAP];

void dead_loop(void);
void sleep_ms(long milliseconds);

int main () {
    int total_time = 500;
    float percent[GAP];
    for (int i = 0; i < GAP; i++) {
        percent[i] = 0.25 * sin(0.5 * i) + 0.75;
        busy_time[i] = total_time * percent[i];
        idle_time[i] = total_time - busy_time[i];
    }

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
    while (1) {
        for (int j = 0; j < GAP; j++) {
            for (int k = 0; k < 10; k++) {
                start = clock();
                while ((clock() - start) / CLOCKS_PER_SEC * 1000 < busy_time[j]) 
                    ;
                sleep_ms(idle_time[j]);
            }
        }
    }
}
