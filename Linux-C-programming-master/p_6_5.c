#include <stdio.h>

void print_mult_table(void) {
    int i;
    for (i = 1; i < 10; i++) {
        int j;
        for (j = 1; j <= i; j++) {
            printf("%d\t", j*i);
        }
        printf("\n");
    }
}

void diamond(int n, char sim) {
    if (n % 2 == 0) {
        printf("Arguement should be and odd num");
        return;
    }
    int mid = n / 2 + 1;
    int i;
    for (i = 1; i < mid+1; i++) {
        for (int j = 0; j < mid - i; j++) {
            printf(" \t");
        }
        for (int j = 0; j < i*2 - 1; j++) {
            printf("%c\t", sim);
        }
        printf("\n");
    }
    for (i = mid-1; i > 0; i--){
        for (int j = 0; j < mid - i; j++) {
            printf("\t");
        }
        for (int j = 0; j < i*2 - 1; j++) {
            printf("%c\t", sim);
        }
        printf("\n");
    }
}

int main(void) {
    print_mult_table();
    diamond(5, '+');
    return 0;
}