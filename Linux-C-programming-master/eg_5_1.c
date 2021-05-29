#include <stdio.h>
#include <math.h>

int is_leap_year(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 != 0 && year % 4 == 0) {
        return 1;
    }
    return 0;
}

double myround(double x) {
    if (x > 0) {
        if (x - floor(x) < 0.5) return floor(x);
        else return ceil(x);
    } else {
        if (ceil(x) - x < 0.5) return ceil(x);
        else return floor(x);
    }
}

int main() {
    printf("%d, %.1f, %.1f", is_leap_year(100), myround(4.49), myround(-3.51));
}