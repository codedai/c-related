#include <stdio.h>

int find_gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    if (a % b == 0) return b;
    else {
        return find_gcd(b, a%b);
    }
}

int main(void) {
    printf("%d\n", find_gcd(-10, -25));
    return 0;
}