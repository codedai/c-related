#include <math.h>
#include <stdio.h>

void print_time(int, int);


int main(void) {
    double pi = 3.1416;
    int num = printf("sin(pi/2)=%f\nln1=%f\n", sin(pi/2), log(1.0));
    printf("There are %d char in the sentence\n", num);
    print_time(10, 10);
    return 0;
}

void print_time(int hour, int minu) {
    printf("%d : %d", hour, minu);
}