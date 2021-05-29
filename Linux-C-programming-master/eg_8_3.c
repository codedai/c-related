#include <stdio.h>
#define N 3

int a[N] = {1, 2, 3};

void changer(int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void printer(int i) {
    if (N-i == 1) {
        for (int j = 0; j < N; j++) printf("%d ", a[j]);
        printf("\n");
    } else {
        for (int j = i; j < N; j++) {
            changer(i, j);
            printer(i+1);
            changer(i, j);
        }
    }
}

int main(void) {
    printer(0);
}
