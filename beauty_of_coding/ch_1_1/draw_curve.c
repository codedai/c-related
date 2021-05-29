#include <stdio.h>
#include <math.h>

const double RES = 0.1;
const double PI = 3.14159265;
const double EPS = 1e-2;

int main (void) {
    double x, y, y_p;
    for (y = 0.0; y >= -2.0; y -= RES) {
        y_p = y + 1;
        for (x = 0.0; x <= 2*PI; x+=RES) {
            if (fabs(sin(x) - y) < EPS)
                printf("*");
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
