// NOT WORKING!!!!!
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

const double SPLIT = 0.01;
const int COUNT = 200;
const double PI = 3.14159265;
const int INTERVAL = 300;

int main(int argc, char * args[]) {
    clock_t busySpan[COUNT];
    clock_t idleSpan[COUNT];

    int half = INTERVAL / 2;
    double radian = 0.0;

    for (int i = 0; i < COUNT; i++) {
        busySpan[i] = (clock_t) (half + (sin(PI * radian) * half));;
        idleSpan[i] = INTERVAL - busySpan[i];
        radian += SPLIT;
    }

    clock_t startTime = 0;
    int j = 0;

    while(1) {
        j = j % COUNT;
        startTime = clock();
        while((clock() - startTime) <= busySpan[j])
            ;
        sleep(idleSpan[j]);
        j++;
    }

    return 0;
}
