#include <stdio.h>

#define LEN 5
int a[LEN] = {10, 5, 2, 4, 7};


void insert(int j) {
    int i, key;
    key = a[j];
    for (i = j-1; i >= 0; i--) {
        if (a[i] > key) {
            a[i+1] = a[i];
        }   
        else break;
    }
    a[i+1] = key;
}

void insertion_sort(void) {
    for (int i = 1; i < LEN; i++) {
        insert(i);
    }
}

int main(void) {
    printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
    insertion_sort();
    printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
    return 0;
}