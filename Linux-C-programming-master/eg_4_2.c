#include <stdio.h>


int main(void) {
    double i = 20.0;
    double j = i / 7.0;
    if (j * 7.0 == i) printf("Equal.\n");
    else printf("Unequal.\n");

    int x = 1234;
    printf("Tens: %d, Units: %d", x/10%10, x%10);
    return 0;
}