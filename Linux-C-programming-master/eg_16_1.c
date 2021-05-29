#include <stdio.h>

int countbit(unsigned int x) {
    unsigned int mask = 1;
    int count = 0;
    while (x != 0) {
        if (x & mask == 1) count++;
        x = x >> 1;
        printf("x is %x\n", x);
    }
    return count;
}

unsigned int multiply(unsigned int x, unsigned int y) {
    unsigned int ans = 0, mask = 1;
    int count = 0;
    while (y != 0) {
        if (y & mask == 1) {
            ans = ans + (x << count);
        }
        count++;
        y = y >> 1;
    }
    return ans;
}

unsigned int rotate_right(unsigned int x, int num) {
    unsigned int tmp, mask = 1, h = 0x80000000;
    for (int i = 0; i < num; i++) {
        tmp = x & mask;
        x = x >> 1;
        if (tmp == 1) x = x | h;
    }
    return x;
}

int main() {
    int i = 0xcffffff3;
    printf("%x\n", 0xcffffff3>>2);
    printf("%x\n", i >> 2);
    printf("%x\n", rotate_right(0xdeadbeef, 16));
    i = 0;
    unsigned int sum = 0;
    for (; i < 30; i++) {
        sum = sum + 1u << 1;
    }
    printf("%x\n", sum);
    return 0;
}